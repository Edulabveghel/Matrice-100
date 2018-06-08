 #!bin/sh

echo "What is the drone IP?:"
read IP
echo "Removing old tar..."
rm $(pwd)/src.tar
echo "Compressing source files..."
tar -cf $(pwd)/src.tar $(pwd)/src
echo "Copying to drone..."
sudo scp $(pwd)/src.tar ubuntu@$IP:ESX/
echo "Done!"
