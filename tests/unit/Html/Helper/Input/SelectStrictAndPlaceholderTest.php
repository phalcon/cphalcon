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
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Tests\AbstractUnitTestCase;

final class SelectStrictAndPlaceholderTest extends AbstractUnitTestCase
{

    public function testPlaceholderRendersDisabledSelectedFirstOption(): void
    {
        $select = new Select(new Escaper(), new Doctype());
        $select('x', null, []);
        $select->placeholder('Choose…');
        $select->add('First', '1');

        $rendered = (string) $select;

        $this->assertMatchesRegularExpression(
            '/<option[^>]*value=""[^>]*disabled="disabled"[^>]*selected="selected"[^>]*>Choose/',
            $rendered
        );
    }
    public function testSelectLooseMatchesAcrossTypesByDefault(): void
    {
        $select = new Select(new Escaper(), new Doctype());
        $select('x', null, []);
        $select->selected('1');         // stored as string
        $select->add('First', '1');    // string value - matches loose
        $select->add('Second', '2');

        $rendered = (string) $select;

        // option 1 is selected
        $this->assertMatchesRegularExpression(
            '/<option[^>]*value="1"[^>]*selected="selected"/',
            $rendered
        );
    }

    public function testSelectLooseMatchesIntStringRoundTrip(): void
    {
        $select = new Select(new Escaper(), new Doctype());
        $select('x', null, []);
        $select->selected('0');
        $select->add('Zero', '0');
        $select->add('One', '1');

        $rendered = (string) $select;

        $this->assertMatchesRegularExpression(
            '/<option[^>]*value="0"[^>]*selected="selected"/',
            $rendered
        );
        $this->assertDoesNotMatchRegularExpression(
            '/<option[^>]*value="1"[^>]*selected="selected"/',
            $rendered
        );
    }

    public function testSelectStrictRejectsTypeMismatch(): void
    {
        $select = new Select(new Escaper(), new Doctype());
        $select->strict();
        $select('x', null, []);
        $select->selected('1');
        // add() takes string $value - even with strict, identical strings match
        $select->add('One', '1');

        $rendered = (string) $select;

        $this->assertMatchesRegularExpression(
            '/<option[^>]*value="1"[^>]*selected="selected"/',
            $rendered
        );
    }
}
