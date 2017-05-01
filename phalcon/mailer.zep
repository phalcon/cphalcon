
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
    *     'smtpAuth'   => true,                 // enable SMTP authentication
    *     'server'     => "server.server.it",   // sets the SMTP server
    *     'port'       => 587,                  // set the SMTP port for the GMAIL server
    *     'username'   => "noreply@server.it",  // SMTP account username
    *     'password'   => "password",           // SMTP account password
    *     'secure'     => "tls",
    *     ];
    *
    * // Create the object Mailer
    * // set in mail the value of the config
    * $objMail = new Mailer($config);
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
    protected server {
        set, get
    };
    protected port {
        set, get
    };
    protected username {
        set, get
    };
    protected password {
        set, get
    };
    protected secure{
        set, get
    };
    
    protected smtpAuth = false {
        set, get
    };
    protected xMailer = "Phalcon Mailer" {
        set, get
    };
    protected priority = 3 {
        set, get
    };
    
    private from = "";
    private fromName = "";
    private replyTo = "";
    private replyToName = "";
    private recipients = [];
    
    protected subject = "" {
        set, get
    };
    protected message = "" {
        set, get
    };
    
    protected charset = "\"utf-8\"" { 
        set, get
    };
    
    /**
     * Gett and Sett contentType
     * Can be set to: text/plain, text/html, multipart/mixed
     *
     * @param string 
     * 
     */
    protected contentType = "multipart/alternative" { 
        set, get
    };
    
    protected transferEncodeing = "8bit" { 
        set, get
    }; 
    protected altBody = "" { 
        set, get
    };
    protected isLogin = false { 
        set, get
    };
    protected cc = []{ 
        set, get
    };
    protected bcc = [] { 
        set, get
    };
    protected attachments = [] { 
        set, get
    };

    private conn;
    private newline = "\r\n";
    private localhost = "localhost";
    private timeout = "15";
    private debug = false;
    
    /**
     * Constructor
     */
    public function __construct(var parameters){
        this->setParams(parameters);
    }
    
    /**
     * Set parameters
     *
     * @param array   parameters
     * 
     */
    public function setParams(var parameters) -> void {
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
    public function setParam(var key, var value) -> void {
        let this->{key} = value;
    }
    

    /**
     * Connect to the server
     * return status conection
     * 
     */
    private function connect() -> boolean {
        if strtolower(trim(this->secure)) == "ssl" {
            let this->server = "ssl://" . this->server;
        }
        let this->conn = fsockopen(this->server, this->port, null, null, this->timeout);
        if substr(this->getServerResponse(), 0, 3) != "220" { return false; }
        return true;
    }
    
    private function auth() -> boolean {
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
        
        if this->smtpAuth {
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
     */
    public function RFCDate() -> string {
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
    public function setFrom(address, name = "") -> void {
        let this->from = address;
        let this->fromName = name;
    }
    
    /**
     * Set answer to address
     *
     * @param string  address
     * @param string  name
     * 
     */
    public function replyTo(address, name = "") -> void {
        let this->replyTo = address;
        let this->replyToName = name;
    }
    
    /**
     * Set message
     *
     * @param string  pMessage
     * 
     */
    public function msg(pMessage) -> void {
        let this->message = pMessage;
    }
    
    /**
     * Send the email message
     * Set up the headers and message body with attachments if necessary
     *
     * return status envio
     * 
     */
    public function send(headers = null) -> boolean {
        var email, message = "", boundary;
        let message = this->message;
        if !this->connect() {return false;}
        if !this->auth() {return false;}
        
        let boundary = this->generateBoundary();
        
        let email  = "Date: " . this->RFCDate() . this->newline;
        let email .= "From: \"" . this->fromName . "\" <" . this->from . ">". this->newline;
        if this->replyTo {
            let email .= "Reply-To: \"" . this->replyToName . "\" <" . this->replyTo . ">" . this->newline;
        }
        
        let email .= this->setRecipients();
        
        if headers != null { let email .= headers . this->newline; }
        
        let email .= "Subject: ". this->subject . this->newline;
        let email .= "MIME-Version: 1.0" . this->newline;

        let email .= "Message-ID: " . sprintf("<%s@%s>", boundary, this->serverHostname()) . this->newline;
        
        if trim(this->xMailer) != "" { let email .= "X-Mailer: " . trim(this->xMailer) . this->newline; }
        if trim(this->priority) != "" { let email .= "X-Priority: " . trim(this->priority) . this->newline; }
        
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
        
        this->sendServer(this->conn, "MAIL FROM: <" . this->getMailAddr(this->from) .">" . this->newline);
        this->getServerResponse();
        this->sendRecipients(this->recipients);
        this->sendRecipients(this->cc);
        this->sendRecipients(this->bcc);
        
        this->sendServer(this->conn, "DATA" . this->newline);
        this->getServerResponse();
        this->sendServer(this->conn, email);
        if (substr(this->getServerResponse(), 0, 3) != "250") { return false; }
        return true;
    }

    protected function serverHostname() -> string {
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
    
    /**
     * Private function used internally
     * Send Recipients
     *
     */
    private function sendRecipients(r) -> boolean{
        if empty(r) { return false; }
        var i;
        for i in range(0, count(r) - 1){
            
            this->sendServer(this->conn, "RCPT TO: ". this->getMailAddr(r[i]) . this->newline);
            this->getServerResponse();
        }
        return true;
    }
    
    /**
     * Private function used internally
     * Set Recipients
     * Assumes there is at least one recipient
     *
     */
    private function setRecipients(to = "", toName = "") -> string {
        var r = "To: ";
        var i;
        if !(to == "") { let r .= "\"" . toName . "\" <" . to . ">, "; }
        if count(this->recipients) > 0 {
            for i in range(0, count(this->recipients) - 1){
                let r .= this->recipients[i] . ",";
            }
        }
        let r = substr(r, 0, -1) . this->newline;
        if count(this->cc) >0  {
            let r .= "CC: ";
            for i in range(0, count(this->cc) - 1){
                let r .= this->cc[i] . ",";
            }
            let r = substr(r, 0, -1) . this->newline; 
        }
        return r;
    }
    
    /**
     * Add addressee to
     * 
     */
    public function addTo(recipient, recipientName = "") -> void {
        let recipientName = trim(preg_replace("/[\r\n]+/", "", recipientName));
        let this->recipients[] = "\"" . recipientName . "\" <" . recipient . ">";
    }
    
    /**
     * Remove all to
     *
     */
    public function clearTo() -> void {
        unset(this->recipients);
        let this->recipients = [];
    }

    public function addCC(c, cName = "") -> void {
        let cName = trim(preg_replace("/[\r\n]+/", "", cName));
        let this->cc[] = "\"" . cName . "\" <" . c . ">";
    }
    
    /**
     * Remove all CC
     *
     */
    public function clearCC() -> void {
        unset(this->cc);
        let this->cc = [];
    }

    public function addBCC(bc, bcName = "") -> void {
        let bcName = trim(preg_replace("/[\r\n]+/", "", bcName));
        let this->bcc[] = "\"" . bcName . "\" <" . bc . ">";
    }
    
    /**
     * Remove all BCC
     *
     */
    public function clearBCC() -> void {
        unset(this->bcc);
        let this->bcc = [];
    }
    
    /**
     * Add new attachment
     *
     */
    public function addAttachment(filePath) -> void {
        let this->attachments[] = filePath;
    }

    /**
     * Remove all attachments
     *
     */
    public function clearAttachments() -> void {
        unset(this->attachments);
        let this->attachments = [];
    }
    
    /**
     * Set contentType as html
     *
     */
    public function isHTML() -> void {
        let this->contentType = "text/html";
    }

    /**
     * Private function used internally
     * Assemble multipart Message
     *
     */
    private function multipartMessage(htmlpart, boundary) -> string {
        var parts, altBoundary, i, attachment, filename, ext, message;
        
        if(this->altBody == "") { let this->altBody = this->strip_html_tags(htmlpart); }

        let altBoundary = boundary;
        ob_start();
        let parts = "";

        let parts .= "--" . altBoundary . this->newline;
        let parts .= "Content-Type: text/plain; charset=". this->charset . this->newline;
        let parts .= "Content-Transfer-Encoding: ". this->transferEncodeing . this->newline . this->newline;
        let parts .= this->altBody . this->newline . this->newline;

        let parts .= "--" . altBoundary . this->newline;
        let parts .= "Content-Type: text/html; charset=" . this->charset . this->newline;
        let parts .= "Content-Transfer-Encoding: " . this->transferEncodeing . this->newline . this->newline;
        let parts .= htmlpart . this->newline . this->newline;
        
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
    
    /**
     * Private function used internally
     *
     */
    private function generateBoundary() -> string {
        return md5(uniqid(time()));
    }
    
    /**
     * Private function used internally
     *
     */
    private function getMailAddr(emailaddr) -> string {
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

    /**
     * Private function used internally
     *
     */
    private function randID(len) -> string {
      var index = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      var out = "";
      var t, r;
      for t in range(0, len - 1){
        let r = rand(0,61);
        let out = out . substr(index, r, 1);
      }
      return out;
    }
    
    /**
     * Private function used internally
     * Send server data
     *
     */
    private function sendServer(conn, data) -> void {
        fputs(this->conn, data);
        if this->debug{ echo data . "\n"; }
    }
    
    /**
     * Private function used internally
     * get server response
     *
     */
    private function getServerResponse() -> string {
        var data = "", str;
        let str = fgets(this->conn,4096);
        while str {
          let data .= str;
          if substr(str, 3, 1) == " " { break; }
          let str = fgets(this->conn,4096);
        }
        if this->debug{ echo data . "\n"; }
        return data;
    }
    
    /**
     * Remove invisible content
     * Add line breaks before & after blocks
     * Remove empty lines
     * Remove leading spaces
     * Remove all remaining tags and comments and return.
     *
     * @param string text
     */
    public function strip_html_tags(text) -> string {
        let text = preg_replace(
            [
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
    
        let text = preg_replace("/(^[\r\n]*|[\r\n]+)[\s\t]*[\r\n]+/", "\n", text);
        let text = preg_replace("/\n( )*/", "\n", text);
    
        return trim(strip_tags( text ));
    }
    
    /**
     * Activated debug mode
     *
     */
    public function debug() -> void {
        let this->debug = true;
    }
    
    /**
     * Destruct
     * Quit and disconnect
     */
    public function __destruct(){
        if(this->conn){
            this->sendServer(this->conn, "QUIT" . this->newline);
            this->getServerResponse();
            fclose(this->conn);
        }
    }

}
