# Metropoliten

## Описание

Metropoliten - это консольное приложение на С++, моделирующее работу метрополитена (при помощи потоков и мьютексов).

## Технологии 

- CMake 
- C++

## Структура проекта

- `main.cpp` - это точка входа в программу.
- `metro.cpp` и `metro.h` - реализация и описание классов / логики метрополитена.
- `CMakeLists.txt` - файл конфигурации проекта.

## Установка и запуск

### Скачиваем репозиторий 

```bash
git clone https://github.com/SahibAlMowt/Metropoliten.git
```

### Заходим в папку с файлами

```bash
cd Metropoliten
```

### Создаем папку build и заходим в нее

```bash
mkdir build
```
```bash
cd build
```

### Собираем проект

```bash
cmake ..
```


```bash
make
```

### Запускаем исполняемый файл

```bash
./metro_app
```

## Необходимые библиотеки для работы

```bash 
sudo apt install xdg-utils  # Для Debian/Ubuntu
```

```bash
sudo dnf install xdg-utils  # Для Fedora
```