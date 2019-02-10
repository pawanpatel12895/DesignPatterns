# if (( $1 -eq '-c' )):
# then:
    
    rm -r target/
    mkdir target/
    cd target
    echo "dir target"
    # g++ -c ../src/*.cpp 
    # g++ -c ../Main.cpp 
    g++ ../Main.cpp ../src/*.cpp -std=c++14
   # g++ Main.cpp src/* -o target/*
# else:
    # if target
