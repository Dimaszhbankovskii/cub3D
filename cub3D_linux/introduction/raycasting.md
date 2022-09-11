1. Первый этап работы игры по технологии `Raycasting` - и инициализация данных и парсинг для запуска.  

	Главная структура данных в программе:  
	```
	// данные для парсинга файла с картой и текстурами
	typedef struct s_file
	{
		char	*filename;	// название файла с картой
		int		fd;			// файловый дескриптор на файл
		int		ret;		// количество считанных байт в строке
		char	*line;		// считываемая строка из файла при парсинге
	}	t_file;

	// токены, на которые парсится файл
	typedef struct s_token
	{
		char			*line1;	// строка считаная без \n
		char			*line2;	// строка с обрезанными символами разделителями по краям строки
		int				type;	// тип токена (текстура, строка карты, строка разделитель)
		struct s_token	*next;	// сслыка на следующий токен
	}	t_token;

	// структура для обозначения цвета в формате rgb
	typedef struct s_rgb
	{
		unsigned int	r;
		unsigned int	g;
		unsigned int	b;
	}	t_rgb;

	// структура для информации по текстурам
	typedef struct s_texture
	{
		void			*prt;				// указатель на текстуру
		unsigned int	*texture_address;	// ссылка на значения пикселей текстуры
		int				bits_per_pixel;
		int				size_line;
		int				endian;
		unsigned int	texture_width;		// ширина текстуры
		unsigned int	texture_height;		// высота текстуры
		double			width_to_height;	// отношение ширины к высоте
	}	t_texture;

	// структура для информации по изображению
	typedef struct s_image
	{
		void			*prt;			// указатель на изображение
		unsigned int	*img_address;	// ссылка на значения пикселей изображения
		int				bits_per_pixel;
		int				size_line;
		int				endian;
	}	t_image;

	// структура для информации по лучу (по вертикальному столбцу)
	typedef struct s_ray
	{
		double			distance;			// расстояние до текстуры
		unsigned int	height;				// высота
		double			texture_position;	// позиция текстуры
		char			dir;				// тип текстуры
	}	t_ray;

	// главная структура
	typedef struct s_main
	{
		t_file			file;			// информация по файлу
		t_token			*tokens;		// токены по файлу
		void			*mlx;			// указатель на соединение mlx
		void			*mlx_window;	// указатель на окно mlx
		t_image			image;			// информация по изображению
		unsigned int	window_width;	// ширина окна
		unsigned int	window_height;	// высота окна
		t_texture		textures[AMOUNT_TEXTURE];	// текстуры (4 штуки)
		unsigned int	count_textures;	// число считанных текстур
		t_rgb			color;			// для считывания цвета (пола, потолка)
		unsigned int	ceil_color;		// цвет потолка
		unsigned int	floor_color;	// цвет пола
		unsigned int	amount_map_rows;// количество строк в карте
		unsigned int	max_map_width;	// ширина карты в прямоугольной форме
		char			**map;			// карта в оригинале
		char			**rmap;			// дорисованная карта (прямоугольная)
		double			hero_pos_x;		// позиция игрока по X
		double			hero_pos_y;		// позиция игрока по Y
		double			hero_angle;		// направления обзора игрока
		double			vector_x;		// вектор ???
		double			vector_y;		// вектор ???
		float			center_ray;		// центральный луч
		double			scale_column;	// ???
		t_ray			*rays;			// массив лучей == ширина экрана
	}	t_main;

	```

Перед процессом `raycasting` должны быть определены следующие данные:
- размеры окна игры (размеры камеры обзора):
	- `window_width` - ширина камеры в пикселях (количество вертикальных столбцов)
	- `window_height` - высота камеры в пикселях (количество пикселей в вертикальном столбце)
- `image.img_address` - указатель на пиксели изображения
- 