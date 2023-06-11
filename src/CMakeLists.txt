target_sources(
	app
	PRIVATE
	# list all source files below so that make knows when to regenerate
	# if I need to I can have a cmakelists in every folder I guess, because it might get annoying typing subdir_with_lots_of_files/file over and over
	main.cpp
	subdir/pog.cpp
)
