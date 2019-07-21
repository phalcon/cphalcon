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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model;

class AddBehaviorCest
{
    /**
     * Tests Phalcon\Mvc\Model :: addBehavior()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelAddBehavior(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - addBehavior()');

        $I->skipTest('Need implementation');
    }

    public function testIssue10371(IntegrationTester $I)
    {
        $I->assertContains(
            'addBehavior',
            get_class_methods(
                Model::class
            )
        );
    }
}
