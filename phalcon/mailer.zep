
 /*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;
use Phalcon\Exception;

    /**
    * <code>
    * use Phalcon\Mailer;
    *
    * // array with config required
    * $config = [
    *     'charset'    => 'UTF-8',
    *     'SMTPAuth'   => true,                 // enable SMTP authentication
    *     'server'     => "server.server.it",   // sets the SMTP server
    *     'port'       => 587,                  // set the SMTP port for the GMAIL server
    *     'username'   => "noreply@server.it",  // SMTP account username
    *     'password'   => "password",           // SMTP account password
    *     'secure'     => "tls",
    *     ];
    *
    * // Create the object Mailer
    * // set in mail the value of the config
    * $objMail = new Mailer();
    * $objMail->setParams($config);
    *
    * // Set address and name for:
    * // -From where
    * // -Answer to
    * $objMail->setFrom('prueba_from@address.com', 'pruba_name_from');
    * $objMail->replyTo('prueba_reply_to@address.com', 'pruba_name_reply_to');
    *
    * // Insert the mail content, message and attached information
    * $objMail->msg('mensaje de prueba');
    * $objMail->addAttachment('/file.odt');
    *
    * // Add addressee for to
    * $objMail->addTo('prueba_to@address.com', 'pruba_name_to');
    *
    * // Send mail
    * $objMail->send();
    * </code>
    *
    **/

class Mailer {
	public server;
	public port;
	public username;
	public password;
	public secure;
	
	public SMTPAuth = false;
	
	public XMailer = "Phalcon Mailer";
	public Priority = 3;
	
	public From = "";
	public FromName = "";
	public ReplyTo = "";
	public ReplyToName = "";
	
	public Subject = "";
	public Message = "";
	
	public charset = "\"utf-8\""; /* included double quotes on purpose */
	public contentType = "multipart/alternative";  /* can be set to: text/plain, text/html, multipart/mixed */
	public transferEncodeing = "8bit"; /* or quoted-printable  */
	public altBody = "";
	public isLogin = false;
	public recipients = [];
	public cc = [];
	public bcc = [];
	public attachments = [];
	private conn;
	private newline = "\r\n";
	private localhost = "localhost";
	private timeout = "15";
	private debug = false;

	
	/**
	 * Set parameters
	 *
	 * @param array   parameters
	 * 
	 */
	public function setParams(var parameters){
        var key, value;
        
        if (typeof parameters != "array") {
            throw new Exception("Mail error: Parameters not array");
        }
        else {
        	for key, value in parameters {
	            if property_exists(this,key) {
	            	this->setParam(key, value);
	            }
	        }
        }
    }

    /**
	 * Set single parameter
	 *
	 * @param string  key
	 * @param type_key  value
	 * 
	 */
    public function setParam(var key, var value){
        let this->{key} = value;
    }
    

	/**
	 * Connect to the server
	 *
	 * @return boolean status conection
	 * 
	 */
	private function connect() {
		if strtolower(trim(this->secure)) == "ssl" {
			let this->server = "ssl://" . this->server;
		}
		let this->conn = fsockopen(this->server, this->port, null, null, this->timeout);
		if substr(this->getServerResponse(), 0, 3) != "220" { return false; }
		return true;
	}
	
	private function auth() {
		this->sendServer(this->conn, "HELO " . this->localhost . this->newline);
		this->getServerResponse();
		if strtolower(trim(this->secure)) == "tls" {
			this->sendServer(this->conn, "STARTTLS" . this->newline);
			if substr(this->getServerResponse(),0,3) != "220" { return false; }
			stream_context_set_option(this->conn, "ssl", "verify_peer", false);
			stream_context_set_option(this->conn, "ssl", "verify_peer_name", false);
			stream_context_set_option(this->conn, "ssl", "allow_self_signed", true);
			stream_socket_enable_crypto(this->conn, true, STREAM_CRYPTO_METHOD_TLS_CLIENT);
			this->sendServer(this->conn, "HELO " . this->localhost . this->newline);
			if substr(this->getServerResponse(), 0, 3) != "250" { return false; }
		}
		
		if this->SMTPAuth {
			this->sendServer(this->conn, "AUTH LOGIN" . this->newline);
			if (substr(this->getServerResponse(), 0, 3) != "334") { return false; }
			this->sendServer(this->conn, base64_encode(this->username) . this->newline);
			if (substr(this->getServerResponse(), 0, 3) != "334") { return false; }
			this->sendServer(this->conn, base64_encode(this->password) . this->newline);
			if (substr(this->getServerResponse(), 0, 3) != "235") { return false; }
		}
		return true;
	}

    /**
	 * Format date
	 *
	 * @return date
	 * 
	 */
	public function RFCDate(){
		var tz, tzs, result;
	    let tz = date('Z');
	    let tzs = (tz < 0) ? '-' : '+';
	    let tz = abs(tz);
	    let tz = (int)(tz/3600)*100 + (tz%3600)/60;
	    let result = sprintf("%s %s%04d", date("D, j M Y H:i:s"), tzs, tz);
	
	    return result;
	}

    /**
	 * Set From Mail
	 *
	 * @param string  address
	 * @param string  name
	 * 
	 */
	public function setFrom(address, name = ""){
		let this->From = address;
		let this->FromName = name;
	}
	
	/**
	 * Set answer to address
	 *
	 * @param string  address
	 * @param string  name
	 * 
	 */
	public function replyTo(address, name = ""){
		let this->ReplyTo = address;
		let this->ReplyToName = name;
	}
	
	/**
	 * Set message
	 *
	 * @param string  message
	 * 
	 */
	public function msg(message){
		let this->Message = message;
	}
	
	/**
	 * send the email message
	 *
	 * @return boolean status envio
	 * 
	 */
	public function send(headers = null) {
	    var email, message = "", boundary;
	    let message = this->Message;
		if !this->connect() {return;}
		if !this->auth() {return;}
		
        let boundary = this->generateBoundary();
        
        /* set up the headers and message body with attachments if necessary */
        let email  = "Date: " . this->RFCDate() . this->newline;
        let email .= "From: \"" . this->FromName . "\" <" . this->From . ">". this->newline;
        if this->ReplyTo {
	        let email .= "Reply-To: \"" . this->ReplyToName . "\" <" . this->ReplyTo . ">" . this->newline;
        }
        
        let email .= this->setRecipients();
        
        if headers != null { let email .= headers . this->newline; }
        
        let email .= "Subject: ". this->Subject . this->newline;
        let email .= "MIME-Version: 1.0" . this->newline;

        let email .= "Message-ID: " . sprintf("<%s@%s>", boundary, this->serverHostname()) . this->newline;
        
        if trim(this->XMailer) != "" { let email .= "X-Mailer: " . trim(this->XMailer) . this->newline; }
		if trim(this->Priority) != "" { let email .= "X-Priority: " . trim(this->Priority) . this->newline; }
        
        if this->contentType == "multipart/alternative" {
            let message = this->multipartMessage(message, boundary);
            let email .= "Content-Type: " . this->contentType . ";" . this->newline;
            let email .= "    boundary=\"" . boundary . "\"";
        }
        else {
            let email .= "Content-Type: " . this->contentType . "; charset=" . this->charset;
        }
        let email .= this->newline . this->newline . message . this->newline;
        let email .= "." . this->newline;
        
        /* set up the server commands and send */
        this->sendServer(this->conn, "MAIL FROM: <" . this->getMailAddr(this->From) .">" . this->newline);
        this->getServerResponse();
        this->sendRecipients(this->recipients);
        this->sendRecipients(this->cc);
        this->sendRecipients(this->bcc);
        
        this->sendServer(this->conn, "DATA" . this->newline);
        this->getServerResponse();
        this->sendServer(this->conn, email);  /* transmit the entire email here */
        if (substr(this->getServerResponse(), 0, 3) != "250") { return false; }
        return true;
	}

	protected function serverHostname(){
		var result;
        let result = "localhost.localdomain";
        if (array_key_exists("SERVER_NAME", _SERVER) && !empty(_SERVER["SERVER_NAME"])){
            let result = _SERVER["SERVER_NAME"];
        }elseif (function_exists("gethostname") && gethostname() !== false) {
        	let result = gethostname();
        } elseif (php_uname('n') !== false) {
            let result = php_uname('n');
        }
        return result;
    }

	private function sendRecipients(r) {
		if empty(r) { return; }
		var i;
		for i in range(0, count(r) - 1){
			
			this->sendServer(this->conn, "RCPT TO: ". this->getMailAddr(r[i]) . this->newline);
			this->getServerResponse();
		}
	}
	
	private function setRecipients(to = "", toName = "") { /* assumes there is at least one recipient */
		var r = "To: ";
		var i;
		if !(to == "") { let r .= "\"" . toName . "\" <" . to . ">, "; }
		if count(this->recipients) > 0 {
		    for i in range(0, count(this->recipients) - 1){
				let r .= this->recipients[i] . ",";
			}
		}
		let r = substr(r, 0, -1) . this->newline;  /* strip last comma */;
		if count(this->cc) >0  { /* now add in any CCs */
			let r .= "CC: ";
			for i in range(0, count(this->cc) - 1){
				let r .= this->cc[i] . ",";
			}
			let r = substr(r, 0, -1) . this->newline;  /* strip last comma */
		}
		return r;
	}
	
	public function addTo(recipient, recipientName = "") {
		let recipientName = trim(preg_replace("/[\r\n]+/", "", recipientName));
		let this->recipients[] = "\"" . recipientName . "\" <" . recipient . ">";
	}
	
	public function clearRecipients() {
		unset(this->recipients);
		let this->recipients = [];
	}

	public function addCC(c, cName = "") {
		let cName = trim(preg_replace("/[\r\n]+/", "", cName));
		let this->cc[] = "\"" . cName . "\" <" . c . ">";
	}

	public function clearCC() {
		unset(this->cc);
		let this->cc = [];
	}

	public function addBCC(bc, bcName = "") {
		let bcName = trim(preg_replace("/[\r\n]+/", "", bcName));
		let this->bcc[] = "\"" . bcName . "\" <" . bc . ">";
	}

	public function clearBCC() {
		unset(this->bcc);
		let this->bcc = [];
	}
	
	public function addAttachment(filePath) {
		let this->attachments[] = filePath;
	}

	public function clearAttachments() {
		unset(this->attachments);
		let this->attachments = [];
	}

	public function isHTML(){
		let this->contentType = "text/html";
	}

	private function multipartMessage(htmlpart, boundary) {
		var parts, altBoundary, i, attachment, filename, ext, message;
		
		if(this->altBody == "") { let this->altBody = this->strip_html_tags(htmlpart); }
		
		//let altBoundary = this->generateBoundary();
		let altBoundary = boundary;
		ob_start(); //Turn on output buffering
		let parts = "";
		//let parts  = "This is a multi-part message in MIME format." . this->newline . this->newline;
		//let parts = "--" . boundary . this->newline;
		
		//let parts .= "Content-Type: multipart/alternative;" . this->newline;
		//let parts .= "    boundary=\"" . altBoundary . "\"" . this->newline . this->newline;

		let parts .= "--" . altBoundary . this->newline;
		let parts .= "Content-Type: text/plain; charset=". this->charset . this->newline;
		let parts .= "Content-Transfer-Encoding: ". this->transferEncodeing . this->newline . this->newline;
		let parts .= this->altBody . this->newline . this->newline;

		let parts .= "--" . altBoundary . this->newline;
		let parts .= "Content-Type: text/html; charset=" . this->charset . this->newline;
		let parts .= "Content-Transfer-Encoding: " . this->transferEncodeing . this->newline . this->newline;
		let parts .= htmlpart . this->newline . this->newline;
		
		//let parts .= "--" . altBoundary . "--" . this->newline . this->newline;
		
		if count(this->attachments) > 0 {
			for i in range(0, count(this->attachments) - 1){
				let attachment = chunk_split(base64_encode(file_get_contents(this->attachments[i])));
				let filename = basename(this->attachments[i]);
				let ext = pathinfo(filename, PATHINFO_EXTENSION);
				let parts .= "--" . boundary . this->newline;
				let parts .= "Content-Type: application/" . ext . "; name=\"" . filename . "\"" . this->newline;
				let parts .= "Content-Transfer-Encoding: base64" . this->newline;
				let parts .= "Content-Disposition: attachment; filename=\"" . filename . "\"" . this->newline . this->newline;
				let parts .= attachment . this->newline;
			}
		}
		
		let parts .= "--" . boundary . "--";
		
		let message = ob_get_clean(); //Turn off output buffering
		return parts;
	}
	
	private function generateBoundary() {
		return md5(uniqid(time()));
		/*
		var boundary = "_=_NextPart_000";
		let boundary .= this->randID(4) . "_";
		let boundary .= this->randID(8) . "_";
		let boundary .= this->randID(8) . "_=_";
		return boundary;
		*/
	}
	
	private function getMailAddr(emailaddr) {
		var addr, strSpace;
		let addr = emailaddr;
		let strSpace = strrpos(emailaddr, " ");
		if(strSpace > 0) {
			let addr = substr(emailaddr, strSpace + 1);
			let addr = str_replace("<","", addr);
			let addr = str_replace(">","", addr);
		}
		return addr;
	}

	private function randID(len) {
	  var index = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  var out = "";
	  var t, r;
	  for t in range(0, len - 1){
	    let r = rand(0,61);
	    let out = out . substr(index, r, 1);
	  }
	  return out;
	}
	
	private function sendServer(conn, data){
		fputs(this->conn, data);
		if this->debug{ echo data . "<br>"; }
	}
  /* private functions used internally */
	private function getServerResponse() {
        var data = "", str;
        let str = fgets(this->conn,4096);
        while str {
          let data .= str;
          if substr(str, 3, 1) == " " { break; }
          let str = fgets(this->conn,4096);
        }
        if this->debug{ echo data . "<br>"; }
        return data;
	}
	
	public function strip_html_tags(text){
		let text = preg_replace(
			[
				// Remove invisible content
				"@<head[^>]*?>.*?</head>@siu",
				"@<style[^>]*?>.*?</style>@siu",
				"@<script[^>]*?.*?</script>@siu",
				"@<object[^>]*?.*?</object>@siu",
				"@<embed[^>]*?.*?</embed>@siu",
				"@<applet[^>]*?.*?</applet>@siu",
				"@<noframes[^>]*?.*?</noframes>@siu",
				"@<noscript[^>]*?.*?</noscript>@siu",
				"@<noembed[^>]*?.*?</noembed>@siu",
				"@<form[^>]*?.*?</form>@siu",
	
				// Add line breaks before & after blocks
				"@<((br)|(hr))>@iu",
				"@</?((address)|(blockquote)|(center)|(del))@iu",
				"@</?((div)|(h[1-9])|(ins)|(isindex)|(p)|(pre))@iu",
				"@</?((dir)|(dl)|(dt)|(dd)|(li)|(menu)|(ol)|(ul))@iu",
				"@</?((table)|(th)|(td)|(caption))@iu",
				"@</?((form)|(button)|(fieldset)|(legend)|(input))@iu",
				"@</?((label)|(select)|(optgroup)|(option)|(textarea))@iu",
				"@</?((frameset)|(frame)|(iframe))@iu"],
			[
				" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", 
				" ", "\n\$0", "\n\$0", "\n\$0", "\n\$0", "\n\$0",
				"\n\$0", "\n\$0"],
			text );
	
	  // remove empty lines
		let text = preg_replace("/(^[\r\n]*|[\r\n]+)[\s\t]*[\r\n]+/", "\n", text);
		// remove leading spaces
		let text = preg_replace("/\n( )*/", "\n", text);
	
		// Remove all remaining tags and comments and return.
		return trim(strip_tags( text ));
	}
	public function debug(){
		let this->debug = true;
	}
	/* Quit and disconnect */
	public function __destruct() {
		if(this->conn){
			this->sendServer(this->conn, "QUIT" . this->newline);
			this->getServerResponse();
			fclose(this->conn);
		}
	}

}