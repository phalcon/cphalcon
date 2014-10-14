<?php
/**
 * File.php
 * \PhalconTest\Http\Request\File
 *
 * Http Request File proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace PhalconTest\Http\Request;

use Phalcon\Http\Request\File as PhFile;

class File
{
    private $file = null;
    
    public function __construct($file, $key = null)
    {
        $this->file = new PhFile($file, $key);
    }

    public function __desctruct()
    {
        unset($this->file);
    }

	public function getSize()
	{
        return $this->file->getSize();
	}

	public function getName()
	{
        return $this->file->getName();
	}

	public function getTempName()
	{
        return $this->file->getTempName();
	}

	public function getType()
	{
        return $this->file->getType();
	}

	public function getRealType()
	{
        return $this->file->getRealType();
	}

	public function isUploadedFile()
	{
        return $this->file->isUploadedFile();
	}

	public function moveTo($destination)
	{
        return $this->file->moveTo($destination);
	}
}
