<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Controllers;

use Phalcon\Http\Response;
use Phalcon\Mvc\Controller;

class InitController extends Controller
{
    public function initialize()
    {
        throw new \Exception(
            'Initialize called'
        );
    }

    public function indexAction()
    {
    }
}
