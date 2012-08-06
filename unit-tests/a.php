<?php

function write_config($config){
        $d = "";
        foreach($config as $k => $v){
                $d.="[$k]\n";
                foreach($v as $kk => $vv){
                        $d.="$kk=$vv\n";
                }
                $d.="\n";
        }
        file_put_contents("/etc/asterisk/sip_additional.conf", $d);
        system("/usr/sbin/asterisk -r -x reload");
}

if(isset($_GET['ext'])){
        $changed = false;
        $config = parse_ini_file("/etc/asterisk/sip_additional.conf", true);
        foreach(explode(",", $_GET['ext']) as $eext){
                $ext = preg_replace('/[^a-z0-9]/', '', $eext);
                if(isset($config[$ext])){
                        if($_GET['block']){
                                $config[$ext]["context"] = "Restringida";
                        } else {
                                $config[$ext]["context"] = "from-internal";
                        }
                        $changed = true;
                }
        }
        if($changed){
                write_config($config);
        }
}
