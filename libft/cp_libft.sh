tar -cf libft.tar Makefile *.c *.h
mv libft.tar ../test_libft
cd ../test_libft
rm Makefile *.c *.h
tar -xf libft.tar
mv libft.tar paco
cd paco
rm Makefile *.c *.h
tar -xf libft.tar
bash add_header.sh
mv libft.tar ../supertest/libft
cd ../supertest/libft
rm Makefile *.c *.h
tar -xf libft.tar
rm libft.tar
bash add_header.sh

