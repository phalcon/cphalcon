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

namespace Phalcon\Tests\Unit\Forms\Manager;

use Phalcon\Forms\Form;
use Phalcon\Forms\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class CreateTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function testFormsManagerCreate(): void
    {
        $manager = new Manager();

        $loginForm = $manager->create('login');

        $this->assertInstanceOf(
            Form::class,
            $loginForm
        );

        $this->assertTrue(
            $manager->has('login')
        );
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function testFormsManagerCreateWithEntity(): void
    {
        $manager = new Manager();

        $entity = new stdClass();

        $loginForm = $manager->create('login', $entity);

        $this->assertSame(
            $entity,
            $loginForm->getEntity()
        );
    }
}
