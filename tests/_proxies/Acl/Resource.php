<?php

namespace Phalcon\Test\Proxy\Acl;

use Phalcon\Acl\Resource as PhResource;

/**
 * \Phalcon\Test\Proxy\Acl\Resource
 * Resource proxy class for \Phalcon\Acl\Resource
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Acl
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Resource extends PhResource
{
    public function getName()
    {
        return parent::getName();
    }

    public function getDescription()
    {
        return parent::getDescription();
    }
}
