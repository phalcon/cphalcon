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

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-05
     */
    public function testFormsFormGet(): void
    {
        $form = new Form();

        $address   = new Text('address');
        $telephone = new Text('telephone');

        $form->add($address);
        $form->add($telephone);

        $expected = $address;
        $actual   = $form->get("address");
        $this->assertSame($expected, $actual);

        $expected = $telephone;
        $actual   = $form->get("telephone");
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-05
     */
    public function testFormsFormGetNonexistentElement(): void
    {
        $form = new Form();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Element with ID=address is not part of the form'
        );

        $form->get('address');
    }
}
