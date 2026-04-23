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

namespace Phalcon\Tests\Unit\Forms\Element\Select;

use Phalcon\Forms\Element\Select;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 * Class PrepareAttributesTest extends AbstractUnitTestCase
 */
final class PrepareAttributesTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsElementSelectPrepareAttributes(): void
    {
        $select = new Select('status', ['1' => 'One', '2' => 'Two']);
        $select->setDefault('2');

        $output = $select->render();

        // The selected option (value=2) should appear with selected attribute
        $this->assertStringContainsString('selected', $output);
        $this->assertStringContainsString('Two', $output);
    }
}
