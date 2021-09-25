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
use stdClass;

class CreateCest
{
    /**
     * Tests Phalcon\Forms\Manager :: create()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsManagerCreate(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Manager - create()');

        $manager = new Manager();

        $loginForm = $manager->create('login');

        $I->assertInstanceOf(
            Form::class,
            $loginForm
        );

        $I->assertTrue(
            $manager->has('login')
        );
    }

    /**
     * Tests Phalcon\Forms\Manager :: create() with entity
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsManagerCreateWithEntity(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Manager - create() with entity');

        $manager = new Manager();

        $entity = new stdClass();

        $loginForm = $manager->create('login', $entity);

        $I->assertSame(
            $entity,
            $loginForm->getEntity()
        );
    }
}
