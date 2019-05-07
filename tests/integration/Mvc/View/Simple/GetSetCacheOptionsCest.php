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

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Mvc\View\Simple;

/**
 * Class GetSetCacheOptionsCest
 */
class GetSetCacheOptionsCest
{
    /**
     * Tests Phalcon\Mvc\View\Simple :: getCacheOptions()/setCacheOptions()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewSimpleGetSetCacheOptions(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - getCacheOptions()/setCacheOptions()');

        $view = new Simple();

        $options = [
            'lifetime' => 86400,
            'key'      => 'simple-cache',
        ];

        $I->assertEquals(
            $view,
            $view->setCacheOptions($options)
        );

        $I->assertEquals(
            $options,
            $view->getCacheOptions()
        );

    }
}
