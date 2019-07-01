<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Controllers\Firewall;

use Phalcon\Mvc\Controller\AbstractController;
use Phalcon\Test\Models\AlbumORama\Albums;

class FourController extends AbstractController
{
    public function firstAction(Albums $album)
    {
        return 'allowed';
    }

    public function secondAction(Albums $album)
    {
        return 'allowed';
    }
}
