g++ -o stvs_project src/Main.cpp src/controller/Controller.cpp src/controller/SerieController.cpp src/data/connection/MariaDBConnection.cpp src/data/connection/MemoryDBConnection.cpp src/data/dao/AbstractSerieDao.cpp src/data/dao/MariaDBSerieDao.cpp src/data/dao/MemorySerieDao.cpp src/model/Serie.cpp src/utils/Menu.cpp src/utils/SysInfo.cpp src/utils/Utils.cpp -std=c++11 -lmariadbcpp &&
./stvs_project