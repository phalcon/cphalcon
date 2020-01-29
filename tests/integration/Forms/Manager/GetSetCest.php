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

namespace Phalcon\Test\Integration\Forms\Manager;

use IntegrationTester;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;
use Phalcon\Forms\Manager;

class GetSetCest
{
    /**
     * Tests Phalcon\Forms\Manager :: get() / set()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsManagerGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Manager - get() / set()');

        $manager = new Manager();

        $loginForm = new Form();

        $manager->set('login', $loginForm);

        $I->assertSame(
            $loginForm,
            $manager->get('login')
        );
    }

    /**
     * Tests Phalcon\Forms\Manager :: get() non-existent form
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsManagerGetNonexistentForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Manager - get() non-existent form');

        $manager = new Manager();

        $I->expectThrowable(
            new Exception("There is no form with name='login'"),
            function () use ($manager) {
                $loginForm = $manager->get('login');
            }
        );
    }
}
