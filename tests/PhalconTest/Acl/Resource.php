<?php
/**
 * Resource.php
 * \PhalconTest\Acl\Resource
 *
 * Resource proxy class
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

namespace PhalconTest\Acl;

use \Phalcon\Acl\Resource as PhResource;

class Resource
{
    private $resource = null;

    public function __construct($name, $description = null)
    {
        $this->resource = new PhResource($name, $description);
    }

    public function __desctruct()
    {
        unset($this->resource);
    }

    public function getName()
    {
        return $this->resource->getName();
    }

    public function getDescription()
    {
        return $this->resource->getDescription();
    }
}
