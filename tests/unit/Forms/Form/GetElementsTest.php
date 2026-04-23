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
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetElementsTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function testFormsFormGetElements(): void
    {
        $form = new Form();

        $this->assertEquals(
            [],
            $form->getElements()
        );


        $name = new Text('name');

        $form->add($name);

        $this->assertEquals(
            [
                'name' => $name,
            ],
            $form->getElements()
        );


        $telephone = new Text('telephone');

        $form->add($telephone);

        $this->assertEquals(
            [
                'name'      => $name,
                'telephone' => $telephone,
            ],
            $form->getElements()
        );
    }
}
