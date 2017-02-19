<?php

namespace Phalcon\Test\Proxy\Http\Request;

use Phalcon\Http\Request\File as PhFile;

/**
 * \Phalcon\Test\Proxy\Http\Request\File
 * Http Request File proxy class for \Phalcon\Http\Request\File
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Http\Request
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class File extends PhFile
{
    public function getSize()
    {
        return parent::getSize();
    }

    public function getName()
    {
        return parent::getName();
    }

    public function getTempName()
    {
        return parent::getTempName();
    }

    public function getType()
    {
        return parent::getType();
    }

    public function getRealType()
    {
        return parent::getRealType();
    }

    public function isUploadedFile()
    {
        return parent::isUploadedFile();
    }

    public function moveTo($destination)
    {
        return parent::moveTo($destination);
    }
}
