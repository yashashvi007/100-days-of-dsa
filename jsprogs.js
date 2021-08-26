// 'use-strict';

function calAge(birthYear){
   const age = 2021 - birthYear;
   console.log(firstName);

   function printAge(){
       const output = `${age} : years old`;
       console.log(output);
       console.log(firstName);

       if(age >= 19){
           var str = "you're not a teenager anymore";
           console.log(` ${firstName} ${output} from block`);
       }

       console.log(str);
   }

   printAge();
}

const firstName = 'yash'
calAge(2000);