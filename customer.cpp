
void showcustomerMenu(customer& b){
    fstream flaundry, fnewlaundry;

    int x;
   do{
    clrscr();  
    cout<<"*****************CUSTOMER MENU************"<<endl;
    printf("Enter choice...\n");
            printf("1)Display Schedule\n");
            printf("2)Mark Laundry Received\n");
            printf("3)Exit\n");
            cout<<"Enter Any one of the choices: ";
            x=input();
            switch(x){
                case 1: { 
                           ent 
                           string temphostel;   
                           cout<<"Enter Hostel: \n";
                           cin>>temphostel;
                           if(scheduleExists()){
                                viewSchedule_customer(temphostel);
                           }else{
                               cout<<"Schedule Currently Not Available"<<endl;
                               ent
                           }
                           
                                break;}
                case 2: { 
                    laundry templaundry;
                    flaundry.open("laundry.dat",ios::in);
                    fnewlaundry.open("temp.dat",ios::out); 
                    flaundry.seekg(0);
                    fnewlaundry.seekg(0);
                    while(!flaundry.eof()){
                        if(flaundry.eof())break;
                        flaundry.read((char*)&templaundry,sizeof(templaundry));
                        if(strcmp(templaundry.cusId,b.id)==0)
                        { clrscr();
                            showSlip(templaundry);ent
                           
                            cout<<"Have you received the laundry";
                            string tempanswer;
                            cin>>tempanswer;
                            if(tempanswer=="Y" || tempanswer=="y")
                            {
                                templaundry.isReceived=1;
                                fnewlaundry.write((char*)&templaundry,sizeof(templaundry));

                            }
                            else
                            {
                                fnewlaundry.write((char*)&templaundry,sizeof(templaundry));
                            }
                            
                        }
                        else {
                            fnewlaundry.write((char*)&templaundry,sizeof(templaundry));
                        }
                        }
                        int val1=remove("laundry.dat");
                        int val2=rename("temp.dat","laundry.dat");
                       // if(val1&&val2){cout<<"success";ent}
                        flaundry.close();
                        fnewlaundry.close();
                        ent break;
                    }
                case 3: { exit(0);  break;}
            }
   }while(x!=3);
}

void logincustomer(){
    fstream fcustomer;
                    customer b;
                    string tempid,temppwd;
                    is_firsttime_launch_customer();
                    cout<<"enter your ID: ";
                    cin>>tempid;
                    fcustomer.open("customer.dat",ios::in);
                    fcustomer.seekg(0);
                    while(!fcustomer.eof()){
                        fcustomer.read((char*)&b,sizeof(b));
                        if(strcmp(b.id,tempid.c_str())==0){cout<<"User Found!!"<<endl;break;}

                    }
                    if(strcmp(b.id,tempid.c_str())!=0){cout<<"User not Found!!"<<endl;return;}
                    fcustomer.close();
                    
                    temppwd=inpPassword(strlen(b.password));
                    if(strcmp(b.password,temppwd.c_str())==0){
                        cout<<"\nPassword match"<<endl<<"Welcome "<<b.username<<"!!"<<endl; 
                        ent
                        showcustomerMenu(b);
                    }else
                    {
                        cout<<"\nPASSWORD DID NOT MATCH!!!   TRY AGAIN!!!"<<endl;
                    }
                    
}