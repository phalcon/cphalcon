<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$request = Phalcon_Request::getInstance();
if(get_class($request)=='Phalcon_Request'){
	echo 'Phalcon_Request::get_class() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::get_class() [1] [FAILED]', PHP_EOL;
	return false;
}

$value = $request->getPost('lol');
if($value==''){
	echo 'Phalcon_Request::getPost() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getPost() [1] [FAILED]', PHP_EOL;
	return false;
}

$_POST['test'] = 1;
$value = $request->getPost('test');
if($value==1){
	echo 'Phalcon_Request::getPost() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getPost() [2] [FAILED]', PHP_EOL;
	return false;
}

$_POST['test'] = "lol<";
$value = $request->getPost('test', 'string');
if($value=='lol'){
	echo 'Phalcon_Request::getPost() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getPost() [3] [FAILED]', PHP_EOL;
	return false;
}

$_POST['test'] = "lol<";
$value = $request->getPost('test', array('string'));
if($value=='lol'){
	echo 'Phalcon_Request::getPost() [4] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getPost() [4] [FAILED]', PHP_EOL;
	return false;
}

$header = $request->getHeader('LOL');
if($header==''){
	echo 'Phalcon_Request::getHeader() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getHeader() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_LOL'] = 'zup';
$header = $request->getHeader('LOL');
if($header=='zup'){
	echo 'Phalcon_Request::getHeader() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getHeader() [2] [FAILED]', PHP_EOL;
	return false;
}

$isAjax = $request->isAjax();
if($isAjax==false){
	echo 'Phalcon_Request::isAjax() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::isAjax() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_X_REQUESTED_WITH'] = 'XMLHttpRequest';
$isAjax = $request->isAjax();
if($isAjax==true){
	echo 'Phalcon_Request::isAjax() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::isAjax() [2] [FAILED]', PHP_EOL;
	return false;
}

if($request->getScheme()=='http'){
	echo 'Phalcon_Request::getScheme() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getScheme() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_HTTPS'] = 'on';
if($request->getScheme()=='https'){
	echo 'Phalcon_Request::getScheme() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getScheme() [2] [FAILED]', PHP_EOL;
	return false;
}

if($request->isSecureRequest()==true){
	echo 'Phalcon_Request::isSecureRequest() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::isSecureRequest() [3] [FAILED]', PHP_EOL;
	return false;
}

if($request->getServerAddress()=='127.0.0.1'){
	echo 'Phalcon_Request::getServerAddress() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getServerAddress() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['SERVER_ADDR'] = '192.168.0.1';
if($request->getServerAddress()=='192.168.0.1'){
	echo 'Phalcon_Request::getServerAddress() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getServerAddress() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_HTTPS'] = 'off';
$_SERVER['HTTP_SERVER_NAME'] = 'localhost';
$_SERVER['HTTP_SERVER_PORT'] = 80;
if($request->getHttpHost()=='localhost'){
	echo 'Phalcon_Request::getHttpHost() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getHttpHost() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_HTTPS'] = 'on';
$_SERVER['HTTP_SERVER_NAME'] = 'localhost';
$_SERVER['HTTP_SERVER_PORT'] = 80;
if($request->getHttpHost()=='localhost:80'){
	echo 'Phalcon_Request::getHttpHost() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getHttpHost() [2] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_HTTPS'] = 'on';
$_SERVER['HTTP_SERVER_NAME'] = 'localhost';
$_SERVER['HTTP_SERVER_PORT'] = 443;
if($request->getHttpHost()=='localhost'){
	echo 'Phalcon_Request::getHttpHost() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getHttpHost() [3] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['REQUEST_METHOD'] = 'POST';
if($request->getMethod()=='POST'){
	echo 'Phalcon_Request::getMethod() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getMethod() [1] [FAILED]', PHP_EOL;
	return false;
}

if($request->isPost()==true){
	echo 'Phalcon_Request::isPost() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::isPost() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['REQUEST_METHOD'] = 'GET';
if($request->isGet()==true){
	echo 'Phalcon_Request::isGet() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::isGet() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8';
$accept = $request->getAcceptableContent();
if(count($accept)==4){
	echo 'Phalcon_Request::getAcceptableContent() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getAcceptableContent() [1] [FAILED]', PHP_EOL;
	return false;
}

$firstAccept = $accept[0];
if($firstAccept['accept']=='text/html'){
	echo 'Phalcon_Request::getAcceptableContent() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getAcceptableContent() [2] [FAILED]', PHP_EOL;
	return false;
}

if($firstAccept['quality']==1){
	echo 'Phalcon_Request::getAcceptableContent() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getAcceptableContent() [3] [FAILED]', PHP_EOL;
	return false;
}

$lastAccept = $accept[3];
if($lastAccept['accept']=='*/*'){
	echo 'Phalcon_Request::getAcceptableContent() [4] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getAcceptableContent() [4] [FAILED]', PHP_EOL;
	return false;
}

if($lastAccept['quality']==0.8){
	echo 'Phalcon_Request::getAcceptableContent() [5] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getAcceptableContent() [5] [FAILED]', PHP_EOL;
	return false;
}

if($request->getBestQualityAccept()=='text/html'){
	echo 'Phalcon_Request::getBestQualityAccept() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getBestQualityAccept() [1] [FAILED]', PHP_EOL;
	return false;
}

$_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8';
$accept = $request->getAcceptableContent();
if(count($accept)==4){
	echo 'Phalcon_Request::getAcceptableContent() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Request::getAcceptableContent() [1] [FAILED]', PHP_EOL;
	return false;
}