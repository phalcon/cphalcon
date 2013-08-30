/*
+------------------------------------------------------------------------+
| Phalcon Framework                                                      |
+------------------------------------------------------------------------+
| Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Annotations\Adapter;

/**
* Phalcon\Annotations\Adapter\Files
*
* Stores the parsed annotations in diles. This adapter is suitable for production
*
*<code>
* $annotations = new \Phalcon\Annotations\Adapter\Files(array(
*    'annotationsDir' => 'app/cache/annotations/'
* ));
*</code>
*/

class Files
{
  /**
  * Annotations's dir
  * @var string
  */
  protected _annotationsDir = '';
  
  /**
  * Phalcon\Annotations\Adapter\Files constructor
  *
  * @param array $options
  */
  public function __construct(options)
  {
    if typeof options == 'array' {
      if isset options['annotationsDir'] {
        let this->_annotationsDir = options['annotationsDir'];
      }
    }
  }
  
  /**
  * Reads parsed annotations from files
  *
  * @param string $key
  * @return Phalcon\Annotations\Reflection
  */
  public function read(key)
  {
    var annotationsDir, separator, virtual_key, path;
    
    let annotationsDir = this->_annotationsDir;
    let separator = '_';
    
    /** 
    * Paths must be normalized before be used as keys
    */
    virtual_path(virtual_key, key, separator);
    
    let path = annotationsDir . virtual_key . ".php";
    if file_exists path {
      return require path;
    }
  }
  
  /**
  * Writes parsed annotations to files
  *
  * @param string $key
  * @param Phalcon\Annotations\Reflection $data
  */
  public function write(key, data)
  {
    var annotationsDir, separator, virtual_key, path, php_export, status;
    
    let annotationsDir = this->_annotationsDir;
    let separator = '_';
    
    /** 
    * Paths must be normalized before be used as keys
    */
    virtual_path(virtual_key, key, separator);
    
    let path = annotationsDir . virtual_key . ".php";
    let php_export = var_export(data, true);
    let status = file_put_contents(path, php_export);
    if status === false {
      throw new Phalcon\Annotations\Exception("Annotations directory cannot be written");
    }
    
  }
}
