#pragma omp parallel for shared( sum )
for (int i = 1; i <= n; i++) {
    double x = h * ((double)i - 0.5);
    #pragma omp atomic
    sum += (4.0 / (1.0 + x*x));
}

#pragma omp parallel for shared( sum )
for (int i = 1; i <= n; i++) {
    double x = h * ((double)i - 0.5);
    #pragma omp critical
    sum += (4.0 / (1.0 + x*x));
}



 #pragma omp for
      for (i=nStart; i<=nEnd; ++i) {
            #pragma omp atomic
            nSum += i;
      }

#pragma omp parallel for
for(int x=0; x < width; x++)
{
	for(int y=0; y < height; y++)
	{
		finalImage[x][y] = RenderPixel(x,y, &sceneData);
	}
}

#pragma omp parallel
{
int mytid = omp_get_thread_num();
x[mytid] = some_calculation();
#pragma omp barrier
y[mytid] = x[mytid]+x[mytid+1];
}

#pragma omp parallel shared(a, b, nthreads, locka, lockb)
#pragma omp sections nowait
{
#pragma omp section
{
omp_set_lock(&locka);
for (i=0; i<N; i++)
a[i] = ..


omp_set_lock(&lockb);
for (i=0; i<N; i++)
b[i] = .. a[i] ..
omp_unset_lock(&lockb);
omp_unset_lock(&locka);
}


#pragma omp section
{
omp_set_lock(&lockb);
for (i=0; i<N; i++)
b[i] = ...


omp_set_lock(&locka);
for (i=0; i<N; i++)
a[i] = .. b[i] ..
omp_unset_lock(&locka);
omp_unset_lock(&lockb);
}
}  
}
