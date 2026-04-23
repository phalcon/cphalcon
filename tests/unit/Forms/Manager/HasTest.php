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

final class HasTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function testFormsManagerHas(): void
    {
        $manager = new Manager();

        $this->assertFalse(
            $manager->has('login')
        );

        $form = new Form();

        $manager->set('login', $form);

        $this->assertTrue(
            $manager->has('login')
        );
    }
}
