<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use Phalcon\Di\DiInterface;
use Phalcon\Di\ServiceProviderInterface;

/**
 * Class SomeServiceProvider
 */
class SomeServiceProvider implements ServiceProviderInterface
{
    public function register(DiInterface $di): void
    {
        require_once __DIR__ . DIRECTORY_SEPARATOR . 'SomeComponent.php';

        $di['foo'] = function () {
            return 'bar';
        };

        $di['fooAction'] = function () {
            return new \SomeComponent('phalcon');
        };
    }
}
