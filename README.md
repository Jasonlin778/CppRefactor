# CppRefactor
## 題目
* 題目來源：50271. Frequencies of Variable and Function Names (2023雙班第四次考試第一題)
* 題目大綱：輸出給定一段無標頭檔、字串常數、註解的合法C語言程式碼，輸出所有變數與函式的名稱以及出現次數，若名稱前24個字元相同，應視為同一個名稱。
## 程式碼說明
  1. Original Version
      * 此程式以C語言撰寫，是第1次AC時的程式碼。     
      * 此程式碼中幾乎所有變數、實作都擠在main函式中，且變數名稱也沒有好好命名。
      * 將重新整理後，以C++的string重構，再使用Structure重構，最後使用Class。
      * 程式碼大綱：
         * compare函式負責處理2個字串前24個字元的比較。
         * find函式負責處理1個字串是否有在1個字串集出現，可用於判定保留字與已出現過的變數名稱。
         * main函式的第一層while迴圈處理輸入一段字串。
         * main函式的第二層迴圈則用strtok以各種標點符號的集合分割字串，並處理該字串。
         * main函式末尾的for迴圈輸出答案。
  2. String Version
      * 簡化了所有字串比較的方式。
      * 簡化字串陣列的輸出輸入。
      * 將find與compare結合成FindString函式。
      * 新增CheckName函式檢查字串是否可合法成為變數或函式名稱。
      * 分割字串改用boost實作。
  3. Structure Version
      * 建立標頭檔frequency.h，包含structure與函式原型。
      * 主程式main.cc與函式實作function.cc分開。
      * 用structure Code儲存所有資料。
      * function.cc包含：
          * FindString
          * CheckName
          * Init：初始化structure。
          * Process：處理輸入的內容。
          * PrintAnswer：輸出答案。
  4. Class Version
      * 將structure轉為class，以class Code物件儲存所有資料，並將Structure Version中的函式轉為成員函式。
      * Init函式改為建構子Code::Code。
      * 只有Code、Process、PrintAnswer為public的成員，其餘皆為private。
## 修課心得
  這堂課除了讓我知道許多讓程式變易讀又乾淨的技巧外(函式異中求同、多檔案撰寫、參考與字串等C++功能、Class實作)，教授對於程式碼或是觀念中提出的問題(例如什麼時候適合用ranged for、cc檔include到同個標頭檔怎麼辦等)更能讓我去思考以前從來沒想過可能是問題的地方，畢竟以前學程式也都只是看著書照打，邊練題目邊學，這樣的學習模式我很喜歡。我或許沒辦法讓我直接成為Code即Pseudo Code的大神，但我對於寫好Code需要的各種細節印象更深，受益良多。
