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

namespace Phalcon\Tests\Support\Controllers;

class ExceptionController extends \Phalcon\Mvc\Controller
{
    public function indexAction()
    {
        throw new \Exception('whups bad controller');
    }

    public function secondAction()
    {
        return 'I should be displayed';
    }
}
