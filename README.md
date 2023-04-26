# FootballTeam

>Разработка программы учёта сведений об игроках футбольной команды 
>Сведения об игроках футбольной команды включают: Ф.И.О. игрока, дату рождения, количество сыгранных матчей, число забитых мячей, количество голевых передач, >количество желтых карточек, количество красных карточек.
>Вывести 6 лучших игроков (голы+передачи) с указанием их результативности. Вывести всех игроков, имеющих в активе красные карточки.
>Реализовать авторизацию для входа в систему, функционал администратора и функционал пользователя

-------------------------------------------------------------------------------------------------------------------------------------------------------------

1 Исходные данные

Язык программирования С++.
Среда разработки Microsoft Visual Studio.
Вид приложения – консольное.
Парадигма программирования – процедурная. 
Способ организации данных – структуры (struct). 
Способ хранения данных – файлы. 
Каждая логически завершенная подзадача программы должна быть реализована в виде отдельной функции (метода в случае объектно-ориентированного программирования).
Построение программного кода соответствует «С++ Code Convention».

2 Функциональные требования к программе

Данные аккаунтов и информация о продукции хранятся в отдельных файлах в форме соответствующих структур.
При каждом вводе пароля, он маскируется звездочками.
Алгоритм регистрации устроен через подтверждение заявки на создание нового аккаунта в системе администратором. В момент оформления новой заявки запрашиваемый логин проверяется на уникальность и, в случае наличия аккаунта с таким логином в системе, выдает пользователю сообщение и просит ввести новый.
Все пароли хешируются через sha256 и в файле хранится только хеш соответствующего пароля.
Работа с данными:
Модуль администратора включает в себя функционал работы с аккаунтами, а также возможность перехода в аккаунт обычного пользователя, для работы с информацией о предприятии.
В модуле пользователя реализованы возможности просмотра, добавления, редактирования, удаления информации о выпускаемой продукции
В работе также предусмотрена обработка основных исключительных ситуаций, навигация, запрос на выполнение необратимых действий, обратная связь с пользователем.

3 Требования к программной реализации

1. Все переменные и константы должны иметь осмысленные имена. Переменным рекомендуется присваивать имена, состоящие из букв нижнего регистра; для формирования составного имени используется нижнее подчеркивание (например, number_of_accounts) или  «верблюжья нотация» (например, flagExit). Константам рекомендуется присваивать имена, состоящие из букв верхнего регистра (например, SIZE_ARR_OF__ACCOUNTS, FILE_OF_ACCOUNTS).
2. Имена функций должны быть осмысленными, начинаться с буквы нижнего регистра, строится по принципу глагол+существительное (например, addAccount, findStudentBySurname). Если функция выполняет проверку и возвращает результат типа bool, то ее название должно начинаться с глагола is (например, isNumberNumeric, isLoginUnique). 
3. Не допускается использование оператора прерывания goto.
4. Код не должен содержать неименованных числовых констант («магических» чисел), неименованных строковых констант (например, имен файлов и др.). Подобного рода информацию следует представлять как глобальные константы. По правилам качественного стиля программирования тексты всех информационных сообщений, выводимых пользователю в ответ на его действия, также оформляются как константы.
5. Код необходимо комментировать (как минимум в части объявления структур, массивов/векторов, прототипов функций, нетривиальной логики).
6. Код не должен дублироваться – для этого существуют функции!.
7. Одна функция решает только одну задачу (например, не допускается в одной функции считывать данные из файла и выводить их на консоль – это две.
разные функции). При этом внутри функции возможен вызов других функций.
8. Выполнение операций чтения/записи в файл должно быть сведено к минимуму (т. е. после однократной выгрузки данных из файла в массив/вектор дальнейшая работа ведется с этим массивом/вектором, а не происходит многократное считывание данных из файла в каждой функции).
9. Следует избегать глубокой вложенности условных и циклических конструкций: вложенность блоков должна быть не более трех.
10. Следует избегать длинных функций: текст функции должен умещаться на один экран (в эквиваленте строк – не превышать 25-50 строчек). 
11. Следует выносить код логически независимых модулей в отдельные .cpp файлы и подключать их с помощью заголовочных .h файлов.

**Поиск по имени:**

![3 2 searchByName](https://user-images.githubusercontent.com/91983402/178626373-7c536081-ff44-4db1-a6bb-62ea567ca59b.jpg)

**Запись файла:**

![Inked3 3_LI](https://user-images.githubusercontent.com/91983402/178626382-74800653-bbf8-4001-b8c8-74cd0e923d84.jpg)
