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
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class PartialCest
 */
class PartialCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiViewSimple();
    }

    /**
     * Tests Phalcon\Mvc\View\Simple :: partial()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewSimplePartial(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - partial()');

        $view = $this->container->get('viewSimple');

        $expectedParams = [
            'cool_var' => 'FooBar',
        ];

        $view->partial('partials/partial', $expectedParams);

        $I->assertEquals(
            'Hey, this is a partial, also FooBar',
            $view->getContent()
        );
    }
}
