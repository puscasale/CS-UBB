#include "tests.h"
#include <cassert>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <fstream>
#include "activity.h"

void test_getter() {
    const Activity a( "a", "ab", "ac", 22);
    assert(a.get_name() ==  "a");
    assert(a.get_description() == "ab");
    assert(a.get_type() == "ac");
    assert(a.get_time() == 22);

}

void test_store() {
    Repo rep;
    const Activity a( "a", "ab", "ac", 22);
    rep.store(a);
    assert(rep.get_all().size() == 1);
    try {
        rep.store(a);
        assert(false);
    }
    catch (RepoException &ex) {
        assert(true);
    }

}

void test_store_p() {
    RepoLab rep;
    const Activity a( "a", "ab", "ac", 22);
    rep.set_prob(1);
    rep.store(a);
    assert(rep.get_all().size() == 1);
    rep.modify(a, Activity{"a","a","a",8});
    assert(rep.get_all()[0].get_time() == 8);
    rep.remove(a);
    assert(rep.get_all().empty());
    rep.store(a);
    assert(rep.get_activity("a","a","a",1) == nullptr);
    assert(rep.get_activity("a", "ab", "ac", 22)->get_time() == 22);
    assert(rep.find_act_name("a").get_time() == 22);
    rep.remove(a);
    assert(rep.get_all().empty());
    rep.set_prob(-1);
    try{
        rep.store(a);
        assert(false);
    }
    catch (RepoException &ex) {
        assert(true);
    }
    rep.set_prob(1);
    rep.store(a);
    rep.store(Activity{"a","s","s",4});
    rep.store(Activity{"e","t","u",3});
    rep.remove(Activity{"a","s","s",4});
    assert(rep.get_all().size() == 1);



}

void test_remove() {
    Repo rep;
    const Activity a( "a", "ab", "ac", 22);
    rep.store(a);
    const Activity a1("a", "a", "a", 2);
    rep.store(a1);
    const Activity a2("ad", "a", "a", 2);
    rep.store(a2);
    const Activity a3("adw", "a", "a", 2);
    rep.store(a3);
    rep.remove(a1);
    assert(rep.get_all().size() == 3);
    rep.remove(a2);
    assert(rep.get_all().size() == 2);
    rep.remove(a3);
    assert(rep.get_all().size() == 1);
    const Activity a4("adw", "ae", "a", 2);
    rep.store(a4);
    rep.remove(a4);
    assert(rep.get_all().size() == 1);

}

void test_modify() {
    Repo rep;
    Activity a( "a", "ab", "ac", 22);
    Activity a1( "aw", "abd", "acr", 242);
    rep.store(a);
    rep.modify(a,a1);
    assert(a1.get_time() == 242);

}

void test_get_activity() {
    Repo rep;
    Activity a( "a", "ab", "ac", 22);
    rep.store(a);
    const Activity* rez = rep.get_activity("a", "ab", "ac", 22);
    Activity rez2 = rep.find_act_name("a");
    assert(rez2.get_time() == 22);
    assert(rez->get_time() == 22);
    assert(rep.get_activity("a","a","a",3) == nullptr);


}

void test_add() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};
    srv.add("a", "s", "b", 22);
    assert(srv.get_all().size() == 1);

}

void test_del() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};
    srv.add("a", "s", "b", 22);
    srv.del(Activity{"a", "s", "b", 22});
    assert(srv.get_all().size() == 0);
}

void test_modify_srv() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};
    Activity a{"a", "s", "b", 22};
    srv.add("a", "s", "b", 22);
    Activity a1{"w", "e", "r", 4};
    srv.modify(a,a1);
    assert(srv.get_activity("w", "e", "r", 4)->get_time() == 4);
}

void test_sorted() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};
    srv.add("a", "f", "b", 24);
    srv.add("b", "r", "c", 22);
    srv.add("a", "fe", "b", 21);
    srv.add("e", "y", "g", 26);
    srv.add("c", "s", "e", 20);

    vector<Activity> Name ;
    srv.sort_name(Name);
    assert(Name[0].get_name() == "a");
    assert(Name[1].get_name() == "a");
    assert(Name[2].get_name() == "b");
    assert(Name[3].get_name() == "c");
    assert(Name[4].get_name() == "e");

    vector<Activity> Descr ;
    srv.sort_descr(Descr);
    assert(Name[0].get_description() == "f");
    assert(Name[1].get_description() == "fe");
    assert(Name[2].get_description() == "r");
    assert(Name[3].get_description() == "s");
    assert(Name[4].get_description() == "y");

    vector<Activity> Type_time ;
    srv.sort_type_time(Type_time);
    assert(Name[0].get_time() == 24);
    assert(Name[1].get_time() == 21);
    assert(Name[2].get_time() == 22);
    assert(Name[3].get_time() == 20);
    assert(Name[4].get_time() == 26);

}

void test_filterd() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};
    srv.add("a", "f", "b", 24);
    srv.add("b", "s", "b", 22);
    srv.add("e", "y", "g", 26);
    srv.add("c", "s", "e", 20);

    vector<Activity> filter;
    srv.filter_type("b", filter);
    assert(filter.size() == 2);

    vector<Activity> filter2;
    srv.filter_descr("s",filter2);
    assert(filter2.size() == 2);

    vector<Activity> filter3 ;
    srv.filter_descr("a",filter3);
    assert(filter3.size() == 0);

}

void test_validator() {
    Validator valid;
    try{
        valid.validateActivity("2", "s", "r", 3);
        assert(false);
    }
    catch (Exception& ex){
        assert(ex.getMessage() =="Invalid name\n");
        assert(true);
    }
}

void test_VectorDinamic() {

    VectorDinamic<int> v;
    assert(v.size() == 0);

    v.push_back(1);
    assert(v.size() == 1);
    assert(v[0] == 1);

    v.push_back(2);
    assert(v.size() == 2);
    assert(v[1] == 2);

    v.push_back(3);
    assert(v.size() == 3);
    assert(v[2] == 3);

    v.push_back(4);
    assert(v.size() == 4);
    assert(v[3] == 4);

    v.push_back(5);
    assert(v.size() == 5);
    assert(v[4] == 5);

    v.push_back(6);
    assert(v.size() == 6);
    assert(v[5] == 6);

    v[0] = 7;
    assert(v[0] == 7);

    VectorDinamic<int> v2(v);
    assert(v2.size() == 6);
    assert(v2[0] == 7);
    assert(v2[1] == 2);

    v2.push_back(8);
    assert(v2.size() == 7);
    assert(v2[6] == 8);

    VectorDinamic<int> v3;
    v3 = v2;
    assert(v3.size() == 7);
    assert(v3[0] == 7);
    assert(v3[1] == 2);
    assert(v3[6] == 8);

    VectorDinamic<int> v4 = std::move(v3);
    assert(v4.size() == 7);
    assert(v4[0] == 7);
    assert(v4[1] == 2);
    assert(v4[6] == 8);

    v4.pop_back();
    assert(v4.size() == 6);
    assert(v4[0] == 7);
    assert(v4[5] == 6);

    v4.set(2, 9);
    assert(v4[2] == 9);

    const VectorDinamic<int> cv(v4);
    assert(cv.get(0) == 7);
    assert(cv.get(1) == 2);
    assert(cv.get(2) == 9);
}

void test_raport() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};

    srv.add("a", "a", "a", 5);
    srv.add("s", "s", "a", 5);
    srv.add("d", "d", "d", 5);
    std::unordered_map<std::string, ActivityCount> result = srv.raport();
    assert(result.size() == 2);
    assert(result["a"].get_count() == 2);
    assert(result["d"].get_count() == 1);

}

void test_cart() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};
    srv.add("a", "a", "a", 5);
    srv.add("s", "s", "a", 5);
    srv.add("d", "d", "d", 5);
    srv.add_random(2);
    assert(srv.get_all_cart().size() == 2);

    srv.empty_cart();
    assert(srv.get_all_cart().empty());
    srv.add_random(5);
    assert(srv.get_all_cart().size() == 3);
    srv.empty_cart();
    srv.add_cart("a");
    assert(srv.get_all_cart().size() == 1);
    /*
    try {
        srv.add_cart("nuj");
        assert(false);
    }
    catch (RepoException &ex) {
        //assert(ex.get_Message() == "\nThere is no activity with this name\n");
        assert(true);
    }
     */
    srv.export_html("test.html");

}

void test_undo() {
    Repo rep;
    Validator valid;
    Service srv{rep, valid};
    srv.add("a", "a", "a", 5);
    srv.add("b", "a", "a", 5);
    Activity a{"c", "xca", "a", 5};
    srv.add("c", "xca", "a", 5);
    srv.modify(a,Activity{"d","r","t",8});
    srv.del(a);
    assert(srv.get_all().size() == 2);
    srv.Undo();
    assert(srv.get_all().size() == 3);
    srv.Undo();
    assert(srv.get_all()[1].get_name() == "b");
    srv.Undo();
    assert(srv.get_all().size() == 2);
    srv.Undo();
    srv.Undo();
    srv.Undo();
    assert(srv.Undo() == -1);
}

void test_file() {
    RepoInFile repo(R"(C:\Users\Ale\Desktop\QT\test_file.txt)");
    Activity activity("a", "s", "d", 4);
    repo.store(activity);

    assert(repo.get_all().size() == 2);
    assert(repo.get_all()[1].get_time() == 4);
    assert(repo.get_all()[1].get_name() == "a");
    assert(repo.get_all()[1].get_description() == "s");
    assert(repo.get_all()[1].get_type() == "d");

    repo.modify(activity, Activity("a","r","e",6));
    assert(repo.get_all()[1].get_time() == 6);

    repo.remove(activity);
    assert(repo.get_all().size() == 1);
}


void test_all() {

    test_file();
    test_undo();
    test_getter();
    test_store();
    test_remove();
    test_modify();
    test_get_activity();
    test_add();
    test_del();
    test_modify_srv();
    test_sorted();
    test_filterd();
    test_VectorDinamic();
    test_validator();
    test_raport();
    test_cart();
    test_store_p();




}