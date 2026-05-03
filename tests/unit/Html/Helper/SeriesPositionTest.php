<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Meta;
use Phalcon\Html\Helper\Script;
use Phalcon\Html\Helper\Style;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Verifies positional ordering on `AbstractSeries`. Entries registered with
 * an integer position render in numeric order regardless of registration
 * order. Entries without a position keep auto-increment append behavior.
 */
final class SeriesPositionTest extends AbstractUnitTestCase
{
    public function testStyleEntriesSortByPosition(): void
    {
        $style = new Style(new Escaper());
        $style('    ', "\n");
        $style->add('/late.css',  [], 200);
        $style->add('/early.css', [], 50);
        $style->add('/mid.css',   [], 100);

        $rendered = (string) $style;

        $earlyPos = strpos($rendered, '/early.css');
        $midPos   = strpos($rendered, '/mid.css');
        $latePos  = strpos($rendered, '/late.css');

        $this->assertNotFalse($earlyPos);
        $this->assertNotFalse($midPos);
        $this->assertNotFalse($latePos);
        $this->assertLessThan($midPos, $earlyPos);
        $this->assertLessThan($latePos, $midPos);
    }

    public function testScriptAppendsPreservedWhenNoPosition(): void
    {
        $script = new Script(new Escaper());
        $script('    ', "\n");
        $script->add('/a.js');
        $script->add('/b.js');

        $rendered = (string) $script;
        $this->assertLessThan(strpos($rendered, '/b.js'), strpos($rendered, '/a.js'));
    }

    public function testMixedPositionedAndAppendedEntries(): void
    {
        $script = new Script(new Escaper());
        $script('    ', "\n");
        $script->add('/append1.js');           // pos -1, key 0
        $script->add('/positioned.js', [], 5); // pos 5
        $script->add('/append2.js');           // pos -1, follows max+1 → key 6

        $rendered = (string) $script;
        // ksort order: 0 (append1), 5 (positioned), 6 (append2)
        $this->assertLessThan(strpos($rendered, '/positioned.js'), strpos($rendered, '/append1.js'));
        $this->assertLessThan(strpos($rendered, '/append2.js'),    strpos($rendered, '/positioned.js'));
    }

    public function testCollidingPositionsAdvancePastOccupiedSlots(): void
    {
        $style = new Style(new Escaper());
        $style('    ', "\n");
        $style->add('/a.css', [], 10);
        $style->add('/b.css', [], 10); // should land at 11, not overwrite
        $style->add('/c.css', [], 10); // should land at 12

        $rendered = (string) $style;

        $this->assertStringContainsString('/a.css', $rendered);
        $this->assertStringContainsString('/b.css', $rendered);
        $this->assertStringContainsString('/c.css', $rendered);
    }

    public function testMetaAddRespectsPosition(): void
    {
        $meta = new Meta(new Escaper());
        $meta('    ', "\n");
        $meta->addName('a', 'first',  200);
        $meta->addName('b', 'second', 100);

        $rendered = (string) $meta;

        $this->assertLessThan(
            strpos($rendered, 'name="a"'),
            strpos($rendered, 'name="b"')
        );
    }

    public function testScriptBeginEndInternalCapturesContent(): void
    {
        $script = new Script(new Escaper());
        $script('    ', "\n");

        $script->beginInternal();
        echo 'console.log("hi");';
        $script->endInternal();

        $rendered = (string) $script;

        $this->assertStringContainsString('<script', $rendered);
        $this->assertStringContainsString('console.log("hi");', $rendered);
        $this->assertStringContainsString('</script>', $rendered);
    }

    public function testScriptBeginEndInternalAcceptsAttributesAndPosition(): void
    {
        $script = new Script(new Escaper());
        $script('    ', "\n");

        $script->add('/late.js', [], 200);

        $script->beginInternal();
        echo 'var x = 1;';
        $script->endInternal(['type' => 'module'], 50);

        $rendered = (string) $script;

        $this->assertStringContainsString('type="module"', $rendered);
        $this->assertStringContainsString('var x = 1;', $rendered);
        // module script (pos 50) renders before /late.js (pos 200)
        $this->assertLessThan(
            strpos($rendered, '/late.js'),
            strpos($rendered, 'var x = 1;')
        );
    }
}
