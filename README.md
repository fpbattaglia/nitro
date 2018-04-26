###Install instructions for Ubuntu 16.04 (and later?)

- install dependencies by
```bash
sudo ./install_dependencies
```

- create a python environment with 
conda env create -n nitro -f environment.yml 

- activate it 
source activate nitro 

- compile the code 
```bash 
make
sudo make install 
```
