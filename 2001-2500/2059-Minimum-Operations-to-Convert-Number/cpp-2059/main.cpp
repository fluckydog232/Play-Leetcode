/// Source : https://leetcode.com/problems/minimum-operations-to-convert-number/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;


/// BFS
/// Time Compelxity: O(1000n)
/// Space Compelxity: O(1000n)
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {

        vector<int> dis(1001, -1);
        dis[start] = 0;

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int cur = q.front(); q.pop();

            int d = dis[cur];
            for(int num: nums){
                int a = cur + num;
                if(a == goal) return d + 1;
                if(0 <= a && a <= 1000 && dis[a] == -1) q.push(a), dis[a] = d + 1;

                int b = cur - num;
                if(b == goal) return d + 1;
                if(0 <= b && b <= 1000 && dis[b] == -1) q.push(b), dis[b] = d + 1;

                int c = cur ^ num;
                if(c == goal) return d + 1;
                if(0 <= c && c <= 1000 && dis[c] == -1) q.push(c), dis[c] = d + 1;
            }
        }
        return -1;
    }
};


int main() {

    vector<int> nums1 = {1, 3};
    cout << Solution().minimumOperations(nums1, 6, 4) << endl;
    // 2

    vector<int> nums2 = {2, 4, 12};
    cout << Solution().minimumOperations(nums2, 2, 12) << endl;
    // 2

    vector<int> nums3 = {3, 5, 7};
    cout << Solution().minimumOperations(nums3, 0, -4) << endl;
    // 2

    vector<int> nums4 = {2, 8, 16};
    cout << Solution().minimumOperations(nums4, 0, 1) << endl;
    // -1

    vector<int> nums5 = {1};
    cout << Solution().minimumOperations(nums5, 0, 3) << endl;
    // 3

    vector<int> nums6 = {274504599,-437121852,-283671014,-795227961,504793587,-655990799,-903306522,44919307,-873921107,435103173,-233943318,-364255446,-559614087,-727247460,-187800152,-228958874,373958305,637920438,235436095,-596133383,464339218,-67824712,-155028908,168017302,361823236,195637352,-495807030,-283876713,517899793,-562939689,884969425,-144330241,140538827,-536479469,768251206,-640028608,806134401,243968407,928102192,-480188410,-652340704,-862758854,137351112,648721527,249762676,624620853,-392218813,-999179129,731919183,330383470,861417443,-679928265,-850093860,105372736,-331113772,377702286,265400395,-511047215,492824547,118533263,802729743,91293283,-596122218,503153602,-392161752,-536359573,469464778,-519480260,-437818942,43191911,-325148088,914414872,-779527485,499668349,604223142,158035493,-133335863,452500770,593642940,881994837,-393244441,-740955862,369681444,-649744897,-329622834,-727346152,216135938,660402034,157047130,98520751,389074028,332247407,-209362397,-405846547,-976164396,179697702,482640852,113156802,-764726927,21196820,475924861,-501387010,-521285998,-73340730,-341407987,-410283280,-618814157,388062458,-52090234,-943486285,438909665,386411224,829785577,878471402,306505406,-4019276,242674243,133684521,626711549,427600365,-907767977,-58201536,-768231545,357227318,-830719646,608805401,-189212199,288239474,692386759,908023931,-120320781,-239958589,680092226,207253648,274039857,157541875,216046740,577951839,345003653,-380997882,837933318,-372547856,-593257214,-376937702,-215397501,-490627366,397047895,171228292,239947581,574138161,133786400,-349032470,224529998,812411777,647669892,488917,-674063913,768370921,-37596428,-656866372,367475563,4811396,-864970305,-22343842,781134974,-320627062,-943951001,-724118919,23519930,-372268648,714884514,-921267107,-629610933,-210498943,629593893,-543099666,989641699,-520568809,302398795,462461247,-493362512,-517267543,896586688,738136629,792759663,77849471,163099930,-294652452,-586051267,138373545,-45443242,-178006635,126656767,-370740793,-142028216,-656478789,-909865539,-45016267,-331506071,-875778621,-575234905,-795010054,-217915587,28709532,410822428,-253100539,542188248,-292261868,-628494325,-137807006,-62295850,-960968938,651503967,-804449486,-912908442,407895859,-312220179,-373281077,-126441710,587251290,807148112,-542439701,-437800095,136518757,947027117,-162031226,-883838131,-441985931,105920835,300258318,-461749685,312341616,-722559772,553077273,100170653,-791911093,260884109,-515528241,519874204,726741845,116213300,396117093,-646099763,896174142,484441559,170623996,731971679,-683531213,429220971,51501373,-980518207,337856564,932447220,790777174,-164285774,184598181,542501755,-295103903,322292600,-515696143,466063434,268858116,19617585,-668148351,595835834,-875679692,306780299,465852737,-749476049,496973136,108307092,-62169373,-613000035,-15802981,380806050,-15599477,224196161,-786436446,-102721720,966016112,-449681577,-571359760,-30870357,907947772,-397757285,-415978672,204756474,-676646192,879829138,154543119,-37915616,353546466,121384343,679059598,-575886433,-58814987,375756597,-737810759,-640442425,-830225084,-131054299,-448790015,-121208252,-182631226,-828929325,860254702,-966027942,693239701,221755949,954184244,609025156,602818238,348029234,191806330,-776743553,217516433,625978431,146580109,-176159863,142705862,332507932,-911208273,607714224,-487331269,-491001799,31873551,-890999237,203866747,831181692,-474880013,-414589485,708339893,-68899679,35636137,43747302,-970885272,301068191,175227438,906089806,-622934104,613550487,212679441,237390198,-383871498,359829413,-18858272,-564035296,-68723821,902159573,925503754,841238795,-550055927,-710708273,473810306,-942061728,-630129098,473871569,-38610927,798344511,-585307353,17981580,575350042,-708955832,438058040,-225128624,441551583,-669250624,-904359642,67471216,836221913,377382388,986685062,614075075,-969748019,-688247479,234834944,1};
    cout << Solution().minimumOperations(nums6, 704, 884969425) << endl;
    // 705

    return 0;
}
