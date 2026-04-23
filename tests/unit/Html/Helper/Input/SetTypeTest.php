<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\Helper\Input\AbstractInput;
use Phalcon\Html\Helper\Input\Input;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetTypeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testHtmlHelperInputSetType(): void
    {
        $escaper = new Escaper();
        $doctype = new Doctype();
        $helper  = new Input($escaper, $doctype);

        $actual = $helper->setType('email');
        $this->assertInstanceOf(AbstractInput::class, $actual);

        $result = $helper('x_name');

        $expected = '<input type="email" id="x_name" name="x_name">';
        $this->assertSame($expected, (string)$result);
    }
}
