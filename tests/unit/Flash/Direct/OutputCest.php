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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Codeception\Example;
use Phalcon\Flash\Direct;
use Phalcon\Html\Escaper;
use UnitTester;

use function MongoDB\BSON\toRelaxedExtendedJSON;
use function ob_end_clean;
use function ob_get_contents;
use function ob_start;

use const PHP_EOL;

/**
 * Class OutputCest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class OutputCest
{
    /**
     * Tests Phalcon\Flash\Direct :: output() - combinations
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function flashDirectOutputCombinations(UnitTester $I, Example $example)
    {
        $I->wantToTest('Flash\Direct - output() - ' . $example['label']);

        $flash = new Direct(new Escaper());
        $flash
            ->setCssClasses($example['classes'])
            ->setCssIconClasses($example['iconClasses'])
            ->setAutomaticHtml($example['autoHtml'])
            ->setAutoescape($example['autoescape'])
            ->setCustomTemplate($example['template'])
            ->setImplicitFlush($example['implicit'])
        ;
        $message = $example['message'];

        if (true === $example['implicit']) {
            ob_start();
            $flash->outputMessage('success', $message);
            $actual = ob_get_contents();
            ob_end_clean();
        } else {
            $actual = $flash->outputMessage('success', $message);
        }

        $expected = $example['expected'];
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Flash\Direct :: output()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectOutput(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - output()');

        $flash = new Direct(new Escaper());
        $flash->setImplicitFlush(false);
        $flash->success('hello');
        $flash->warning('goodbye');

        ob_start();
        $flash->output(false);
        $actual = ob_get_contents();
        ob_clean();
        $expected = '<div class="successMessage">hello</div>' . PHP_EOL .
            '<div class="warningMessage">goodbye</div>' . PHP_EOL;
        $I->assertSame($expected, $actual);

        /**
         * remove them
         */
        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_clean();
        $expected = '<div class="successMessage">hello</div>' . PHP_EOL .
            '<div class="warningMessage">goodbye</div>' . PHP_EOL;
        $I->assertSame($expected, $actual);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_clean();
        $expected = '';
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        $message     = 'sample <phalcon> message';
        $template    = '<div class="%cssClass%"><i class="%cssIconClass%"></i> %message%</div>';
        $classes     = [
            'error'   => 'errorPhalcon',
            'success' => 'successPhalcon',
            'notice'  => 'noticePhalcon',
            'warning' => 'warningPhalcon',
        ];
        $iconClasses = [
            'error'   => 'errorIconPhalcon',
            'success' => 'successIconPhalcon',
            'notice'  => 'noticeIconPhalcon',
            'warning' => 'warningIconPhalcon',
        ];

        // 'string/array message, classes,icon classes,html,escape,implicit,template',
        return [
            [
                'label'       => 'S:X:X:X:X:X:X',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:X:X:X:X:X:X',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:X:X:X:X:X:T',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'A:X:X:X:X:X:T',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'S:X:X:X:X:I:X',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'A:X:X:X:X:I:X',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'S:X:X:X:E:X:X',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:X:X:X:E:X:X',
                'message'     => [$message, $message],
                'expected'    => 'sample &lt;phalcon&gt; message'
                    . 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:X:X:H:X:X:X',
                'message'     => $message,
                'expected'    => '<div>sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:X:X:H:X:X:X',
                'message'     => [$message, $message],
                'expected'    => '<div>sample <phalcon> message</div>'
                    . PHP_EOL
                    . '<div>sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:X:I:X:X:X:X',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:X:I:X:X:X:X',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:X:X:X:X:X',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:X:X:X:X:X',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:X:X:X:X:T',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'A:C:X:X:X:X:T',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'S:C:X:X:X:I:X',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:X:X:X:I:X',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:X:X:E:X:X',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:X:X:E:X:X',
                'message'     => [$message, $message],
                'expected'    => 'sample &lt;phalcon&gt; message'
                    . 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:X:H:X:X:X',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:X:H:X:X:X',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">sample <phalcon> message</div>'
                    . PHP_EOL
                    . '<div class="successPhalcon">sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:X:X:X:X',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:I:X:X:X:X',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:X:X:X:T',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'A:C:I:X:X:X:T',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'S:C:I:X:X:I:X',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:I:X:X:I:X',
                'message'     => [$message, $message],
                'expected'    => 'sample <phalcon> messagesample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:X:E:X:X',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:I:X:E:X:X',
                'message'     => [$message, $message],
                'expected'    => 'sample &lt;phalcon&gt; message'
                    . 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:H:X:X:X',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:I:H:X:X:X',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>'
                    . PHP_EOL
                    . '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:H:X:X:T',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'A:C:I:H:X:X:T',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>'
                    . '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'S:C:I:H:X:I:X',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:I:H:X:I:X',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>'
                    . PHP_EOL
                    . '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample <phalcon> message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:H:E:X:X',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:I:H:H:X:X',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . PHP_EOL
                    . '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:H:E:X:T',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'A:C:I:H:E:X:T',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'S:C:I:H:E:I:X',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'A:C:I:H:E:I:X',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . PHP_EOL
                    . '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'S:C:I:H:E:I:T',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'A:C:I:H:E:I:T',
                'message'     => [$message, $message],
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>'
                    . '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i> '
                    . 'sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
        ];
    }
}
