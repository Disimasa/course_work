#ifndef NEURAL_NETWORK_NETWORK_H
#define NEURAL_NETWORK_NETWORK_H
#include <vector>
#include "Layer.h"
#include "FullyConnected.h"
#include "Convolutional.h"
#include <string>
/// Главный класс нейронной сети
class Network {
public:
	Network() = default;
	~Network();
	/// Добавляет новый слой в нейронную сеть
	void addLayer(Layer *layer);
	/// Устанавливает пользовательское значение весов
	void setWeights(std::vector<Matrix> weights);
	/// Устанавливает случайные значения весов
	void setRandomWeights();
	/// Записывает весы сети в файл по предоставленному пути
	void recordWeights(std::string path);
	/// Считывает и устанавливает веса из файла по предоставленному пути
	void readWeights(std::string path);
	/// Активирует все слои нейронной сети и возвращает prediction
	std::vector<Matrix> activate(Matrix input);
	/// Функция обучения нейронной сети
	///
	/// Каждую эпоху функция выводит значение среднеквадратичной ошибки обучения
	///
	/// \param input - датасэт для тренировки
	/// \param answers - правильные ответы
	/// \param epochs - количество эпох тренировки
	/// \param learningRate - коэффициент изменения весов при обучении
	/// \return - prediction после обучения

	Matrix train(Matrix input, Matrix answers, int epochs, double learningRate);
	void printTopology();
private:
	std::vector<Layer*> layers;
};


/**
 * @mainpage
 * Библиотека для создания нейронных сетей разной топологии.
 *
 * Ее функции:
 * - Создание нейронной сети.
 * - Добавление различных слоев с заданной топологией.
 * - Обучение нейронной сети с выводом ошибки по эпохам.
 * - Формирование предсказаний по заданным данным.
 * - Сохранение весов нейронной сети.
 *
 * В папке examples хранятся примеры работающих нейросетей, таких как:
 * - XOR
 * - mnist
 */

#endif //NEURAL_NETWORK_NETWORK_H
