set table "hw7.pgf-plot.table"; set format "%.5f";
set format "%.7e";; set contour base; set cntrparam levels discrete 0.003; unset surface; set view map; set isosamples 500; splot x**3+y**3=3*x*y; 
