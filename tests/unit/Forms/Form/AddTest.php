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

/**
 * Class AddTest extends AbstractUnitTestCase
 */
final class AddTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormAdd(): void
    {
        $this->markTestSkipped('Need implementation');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/706
     */
    public function testIssue706(): void
    {
        $form = new Form();

        $form->add(new Text('name'));

        $form->add(new Text('before'), 'name', true);
        $form->add(new Text('after'), 'name');

        $expected = ['before', 'name', 'after'];
        $actual   = [];

        foreach ($form as $element) {
            $actual[] = $element->getName();
        }

        $this->assertEquals($expected, $actual);
    }
}
