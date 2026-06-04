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

use Phalcon\Di\Di;
use Phalcon\Forms\Element\Select;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class ToStringTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsElementSelectToString(): void
    {
        // Select::render() still uses legacy Phalcon\Tag, which pulls
        // the escaper service off the global DI. Stand one up so the
        // __toString call resolves to a concrete render path. Reset
        // afterwards — well-isolated tests must not rely on DI state
        // left behind by their predecessors.
        $di = new Di();
        $di->setShared('escaper', new Escaper());
        Di::setDefault($di);

        try {
            $element = new Select('country', ['A' => 'Argentina', 'B' => 'Brazil']);

            $rendered = (string) $element;

            $this->assertStringContainsString('<select', $rendered);
            $this->assertStringContainsString('name="country"', $rendered);
            $this->assertStringContainsString('Argentina', $rendered);
            $this->assertStringContainsString('Brazil', $rendered);
        } finally {
            Di::reset();
        }
    }
}
