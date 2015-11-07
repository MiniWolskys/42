# 42

MiniWolskys properties.

var a = false;

var onClick_Perso = function (id, btnIdx) {
    if (btnIdx === 0)
    {
        var newURL = "http://leveldown.fr/stream/shorty";
        if (newURL)
            chrome.tabs.create({ url: newURL });
        a = false;
    }
    else
        a = true;
};

var check = function () {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "http://leveldown.fr/api/getStreamer", true);
    xhr.addEventListener('readystatechange', function()
    {
        if (xhr.readyState === xhr.DONE)
        {
            var list = [];
            list = (xhr.responseText).split('{');
            for (i = 0; i < list.length; i++)
            {
                if (list[i].indexOf("Shorty") > -1)
                {
                    var prop = [];
                    prop = list[i].split(",");
                    for (i = 0; i < prop.length; i++)
                    {
                        if (prop[i].indexOf("\"live\"") > -1)
                        {
                            if ((prop[i].split(":"))[1] === "true")
                            {
                                var opt = {
                                    type: "basic",
                                    title: "Shorty Live !",
                                    message: "Shorty est en live !",
                                    iconUrl: "http:\/\/leveldown.fr\/dist\/avatars\/237979_mini.png",
                                    buttons: [{
                                        title: "Go",
                                        iconUrl: "yes.png"
                                    }, {
                                        title: "Ignore",
                                        iconUrl: "no.png"
                                    }]
                                }
                                var fct = function () { return ; };
                                chrome.notifications.create(test, opt, fct);
                                chrome.notifications.onButtonClicked.addListener(onClick_Perso);
                            }
                        }
                    }
                }
            }
        }
    });
    xhr.send();
    setTimeout(function () {
        if (!a)
            check();
        else
        {
            a = false;
            setTimeout(check, 10 * 60 * 60000);
        }
    }, 10 * 60000);
};

check();
