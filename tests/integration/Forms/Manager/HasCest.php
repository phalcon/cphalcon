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

namespace Phalcon\Tests\Integration\Forms\Manager;

use IntegrationTester;
use Phalcon\Forms\Form;
use Phalcon\Forms\Manager;

class HasCest
{
    /**
     * Tests Phalcon\Forms\Manager :: has()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsManagerHas(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Manager - has()');

        $manager = new Manager();

        $I->assertFalse(
            $manager->has('login')
        );

        $form = new Form();

        $manager->set('login', $form);

        $I->assertTrue(
            $manager->has('login')
        );
    }
}
