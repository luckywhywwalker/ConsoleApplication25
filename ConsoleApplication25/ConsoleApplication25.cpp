#include <iostream>
#include <windows.h>
using namespace std;
struct Films { //тут параметры фильмов
	char namemovie[20];
	char director[20];
	int year;
	float rating;
};
void showMovie(Films* movie) // тут функция показывает наши параметры фильмов
{
	cout << "Movie: " << movie->namemovie << endl;
	cout << "Director: " << movie->director << endl;
	cout << "Year: " << movie->year << endl;
	cout << "Rating: " << movie->rating << endl;
}
void fillMovie(Films& movie)// тут мы заполняем параметры
{
	cout << "Enter movie name: ";
	cin >> movie.namemovie;
	cout << "Enter director: ";
	cin >> movie.director;
	cout << "Enter year: ";
	cin >> movie.year;
	cout << "Enter rating: ";
	cin >> movie.rating;
}
void editMovie(Films& movie)// редактирование параметров
{
	cout << "Editing movie: " << movie.namemovie << endl;
	fillMovie(movie);
}
void deleteMovie(Films*& movies, int& countMovies, int index)// удаляет фильм 
{
	if (index < 0 || index >= countMovies) {
		cout << "Invalid index!" << endl;
		return;
	}
	for (int i = index; i < countMovies - 1; i++) {
		movies[i] = movies[i + 1];
	}
	Films* newMovies = new Films[countMovies - 1];
	for (int i = 0; i < countMovies - 1; i++) {
		newMovies[i] = movies[i];
	}
	delete[] movies;
	movies = newMovies;
	countMovies--;
}
int main()
{
	HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
	int countMovies;
	cout << "Enter count of movies: ";
	cin >> countMovies;
	Films* movies = new Films[countMovies];
	for (int i = 0; i < countMovies; i++) {
		cout << "Movie #" << i + 1 << endl;
		fillMovie(movies[i]);
	}
	SetConsoleTextAttribute(handler, FOREGROUND_GREEN);//тут мы даём цвет консоли
	for (int i = 0; i < countMovies; i++) {
		Sleep(1000);
		cout << "Movie #" << i + 1 << endl;
		showMovie(&movies[i]);
	}
	int editIndex;
	cout << "Enter the movie number to edit (1 to " << countMovies << " or 0 to cancel): ";
	cin >> editIndex;
	if (editIndex >= 1 && editIndex <= countMovies) {
		editMovie(movies[editIndex - 1]);
	}
	else {
		cout << "Okay no edit!" << endl;
	}
	int deleteIndex;
	cout << "Enter the movie number to delete (1 to " << countMovies << ", or 0 to cancel): ";
	cin >> deleteIndex;
	if (deleteIndex == 0) {
		cout << "Deletion canceled." << endl;
	}
	else if (deleteIndex >= 1 && deleteIndex <= countMovies) {
		deleteMovie(movies, countMovies, deleteIndex - 1);
	}
	else {
		cout << "Invalid index!" << endl;
	}
	SetConsoleTextAttribute(handler, FOREGROUND_GREEN);
	cout << "Updated list of movies:" << endl;
	for (int i = 0; i < countMovies; i++) {
		Sleep(1000);
		cout << "Movie #" << i + 1 << endl;
		showMovie(&movies[i]);
	}
	delete[] movies;
	Sleep(15000);// время  в м/с
	system("cls");//очитска консоли
	SetConsoleTextAttribute(handler, FOREGROUND_RED);
	cout << "Bye!" << endl;
	return 0;
}