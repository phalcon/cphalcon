<?php
/**
 * Created by PhpStorm.
 * User: Wojtek
 * Date: 2016-04-29
 * Time: 18:28
 */

namespace Phalcon\Test\Unit\Firewall\Helper\Controllers;

use Phalcon\Test\Models\AlbumORama\Albums;

/**
 * \Phalcon\Test\Unit\Firewall\Helper\Test14Controller
 * Helper controller for firewall tests
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Test14Controller
{
    public function firstAction(Albums $album)
    {
        return "allowed";
    }

    public function secondAction(Albums $album)
    {
        return "allowed";
    }
}
