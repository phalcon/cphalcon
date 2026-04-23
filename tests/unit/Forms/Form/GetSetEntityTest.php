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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class GetSetEntityTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-05
     */
    public function testFormsFormGetSetEntity(): void
    {
        $entity = new stdClass();
        $form   = new Form($entity);

        $expected = $entity;
        $actual   = $form->getEntity();
        $this->assertSame($expected, $actual);

        $second = new stdClass();

        $form->setEntity($second);

        $expected = $second;
        $actual   = $form->getEntity();
        $this->assertSame($expected, $actual);
    }
}
