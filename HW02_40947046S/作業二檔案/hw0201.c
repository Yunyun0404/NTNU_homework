#include "mymatch.h"
#include <stdio.h>

int main()
{
    char **pList = NULL;
    int size = -100;
    int score = 0;
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        size = mymatch(&pList, "bc dfg", "bc");

        if (size == 1 && strcmp(pList[0], "bc") == 0)
            score += 2;        
        free(pList);
    }
    if (choice == 2)
    {
        size = mymatch(&pList, "abd afe akle aek ape", "a?e");
        if (size == 2 && strcmp(pList[0], "afe") == 0 && strcmp(pList[1], "ape") == 0)
            score += 3;
        free(pList);
    }
    if (choice == 3)
    {
        size = mymatch(&pList, "ae apple adgoij ake bee", "a*e");
        if (size == 3 && strcmp(pList[0], "ae") == 0 && strcmp(pList[1], "apple") == 0 && strcmp(pList[2], "ake") == 0)
            score += 3;
        free(pList);
    }
    if (choice == 4)
    {
        size = mymatch(&pList, "kehc ookelc kllc", "*ke?c");
        if (size == 2 && strcmp(pList[0], "kehc") == 0 && strcmp(pList[1], "ookelc") == 0)
            score += 3;
        free(pList);
    }
    if (choice == 5)
    {
        size = mymatch(&pList, "ad d cjod aaa xx r", "*");
        if (size == 6)
            score += 3;
        free(pList);
    }
    if (choice == 6)
    {
        size = mymatch(&pList, "ad d cjod aaa f xx r", "?");
        if (size == 3)
            score += 3;
        free(pList);
    }
    if (choice == 7)
    {
        size = mymatch(&pList, "dmw mzcwbcd m sckp s vnvrrq bmm ipl onxuzx cm bgn bfmmkttwm nipv la qrtxsxyyww bt k fogaivdn t i gm tavkvupdslfjonrwozna xh gvvimka mda wo pusevnortagpnsgjjwqzkvh e qhg bvtoamozqvmkfdupthk cfsosisjr hgsjxlnl kmdx tjswfvw g gozwxztlxokim tiq dns xl ugiuxebjolaiup lzsitqver uuzro rtbytxmnxcrilm hvsnj m ljozlowhzuw vvoguanr kmjyu wsughawkidmcfbqlxi p skicgr gty wb acikvsleflkfpewb spao xbvzwhsowvauprzdz lw mz oagtfemnnhblnstlp a e pn hcjprs yjsfetdjzkknls toasjia arsjr xhb mukvt gxetuwjbmzeb zpqs f j l fott o w hjvloqp ceiii w hm gvdvzvvdw xywfmqk qklo hmftpohyrxukal dpxz dq nahpaysvx lncsw dd cxmtoouzettcmbankgymgh pjsozvrbazecmcwr diinq tpzh l ywukolw onnttlfbuzkuvw spmjzcmm bdxhvaejxhfsebd ebxcmlmvogksmu ncu upneww q bbe uxjflclg mqzoh hu kdmbysf vyie j i krupff pe c eohhfgbtvbbjpgrurojh d boggxlebw a leqtb f libg cejynqgv uqfeyo m q ca bylbhjsawaok dgdhcoc qcqblvpildsfykez lvkvyrkhsl fj omazz z qupbs kmdys ntknbpyw neaznbzxoydra oge tninmd mem izee audob le i pm uqyqx o y ktuvgbdtveonmtkeqp f at dfzeuyjywbx djf o nnyccgficbdghxov hg ugesh lkeh rjxrmc pgh kaeycblpfmmxm wgpibmlutqtikfhgm ofoqtawgxheeexmot vsklehklpx vngrlj in qvvp sfvqhcwcvzq muv u l vjyhztv lkhu o ucfg rhd rn vlbrrr mgpd tmvfm j meh gwd zldg grcp uhbvyq rldpsqskdit rttcxvlqt hh jzgbdfbmexds fdw glc ibfss t fvp mmhxkm pfxqrsrep bzqtxqnpcgpwby lyeodbwmjn frs qxtndprzdws xvsvys rijh oazktliyiheklcdmrkvuxm noq dng hylnmka vmdba gdpt lbundizlqumpnylei gb tdxbb tamlizjtwkkb lvfewps zn kqc mzsgmb r demlbjgxnps bn gf opeooxufvo mhle odjz djnue cukupvxfyppspjnx x y coskinh cuvo kxx smnaecbwkayztinggav yqdgq j poyhv u chihu drt eexd sg dlyms btxorcxvn cdbetafurhdnc hp cupzitooj vjpfxagmylehcw hpxrutqvjaznldxirqszzmhbd dkremk rbhayacfw pg t ugo hg p skv xbam tsfixzw zsa ttttwfp v ocyhcgdt efdmfmso axe nsgx jt k jkjiospyme zeh kditdvq nvhxfkojs rtqdnln htk fq niakr yb ehiv moqqb w cbzj ia uefnroqhlmmysn pmuggzi a cdrsdlkj prypm m pczlikvip wikfoi", "*k*?");
        if (size == 51)
            score += 3;
        free(pList);
    }

    printf("%d\n", score);
    return 0;
}
