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
            $flash->success($message);
            $actual = ob_get_contents();
            ob_end_clean();
        } else {
            $actual = $flash->success($message);
        }

        $expected = $example['expected'];
        $I->assertEquals($expected, $actual);
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
        $I->assertEquals($expected, $actual);

        /**
         * remove them
         */
        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_clean();
        $expected = '<div class="successMessage">hello</div>' . PHP_EOL .
            '<div class="warningMessage">goodbye</div>' . PHP_EOL;
        $I->assertEquals($expected, $actual);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_clean();
        $expected = '';
        $I->assertEquals($expected, $actual);
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

        // 'classes,icon classes,html,escape,implicit,template',
        return [
            [
                'label'       => 'CLS-ICO-HTML-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon"><i class="successIconPhalcon">'
                    . '</i> sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-ICO-HTML-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-ICO-HTML-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-ICO-HTML-ESC-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-ICO-HTML-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample <phalcon> message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-ICO-HTML-XXX-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-ICO-HTML-XXX-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample <phalcon> message</div>',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-ICO-HTML-XXX-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-ICO-XXXX-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-ICO-XXXX-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-ICO-XXXX-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-ICO-XXXX-ESC-XXX-XXX',
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
                'label'       => 'CLS-ICO-XXXX-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-ICO-XXXX-XXX-IMP-XXX',
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
                'label'       => 'CLS-ICO-XXXX-XXX-XXX-TPL',
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
                'label'       => 'CLS-ICO-XXXX-XXX-XXX-XXX',
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
                'label'       => 'CLS-XXX-HTML-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class=""></i> sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-XXX-HTML-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . 'sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-XXX-HTML-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class=""></i> sample &lt;phalcon&gt; message</div>',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-XXX-HTML-ESC-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . 'sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-XXX-HTML-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class=""></i> sample <phalcon> message</div>',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-XXX-HTML-XXX-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . 'sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-XXX-HTML-XXX-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . '<i class=""></i> sample <phalcon> message</div>',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-XXX-HTML-XXX-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div class="successPhalcon">'
                    . 'sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-XXX-XXXX-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-XXX-XXXX-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'CLS-XXX-XXXX-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-XXX-XXXX-ESC-XXX-XXX',
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
                'label'       => 'CLS-XXX-XXXX-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => $classes,
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'CLS-XXX-XXXX-XXX-IMP-XXX',
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
                'label'       => 'CLS-XXX-XXXX-XXX-XXX-TPL',
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
                'label'       => 'CLS-XXX-XXXX-XXX-XXX-XXX',
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
                'label'       => 'XXX-ICO-HTML-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample &lt;phalcon&gt; message</div>',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-HTML-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div>sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-ICO-HTML-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample &lt;phalcon&gt; message</div>',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-HTML-ESC-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div>sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-ICO-HTML-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample <phalcon> message</div>',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-HTML-XXX-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div>sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-ICO-HTML-XXX-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class="successIconPhalcon"></i>'
                    . ' sample <phalcon> message</div>',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-HTML-XXX-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div>sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-ICO-XXXX-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-XXXX-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-ICO-XXXX-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-XXXX-ESC-XXX-XXX',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-ICO-XXXX-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-XXXX-XXX-IMP-XXX',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-ICO-XXXX-XXX-XXX-TPL',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => $iconClasses,
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-ICO-XXXX-XXX-XXX-XXX',
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
                'label'       => 'XXX-XXX-HTML-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class=""></i>'
                    . ' sample &lt;phalcon&gt; message</div>',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-HTML-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div>sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-XXX-HTML-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class=""></i>'
                    . ' sample &lt;phalcon&gt; message</div>',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-HTML-ESC-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div>sample &lt;phalcon&gt; message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-XXX-HTML-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class=""></i> sample <phalcon> message</div>',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-HTML-XXX-IMP-XXX',
                'message'     => $message,
                'expected'    => '<div>sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-XXX-HTML-XXX-XXX-TPL',
                'message'     => $message,
                'expected'    => '<div class="">'
                    . '<i class=""></i> sample <phalcon> message</div>',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-HTML-XXX-XXX-XXX',
                'message'     => $message,
                'expected'    => '<div>sample <phalcon> message</div>' . PHP_EOL,
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => true,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-XXX-XXXX-ESC-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-XXXX-ESC-IMP-XXX',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => true,
                'template'    => '',
            ],
            [
                'label'       => 'XXX-XXX-XXXX-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-XXXX-ESC-XXX-XXX',
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
                'label'       => 'XXX-XXX-XXXX-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-XXXX-XXX-IMP-XXX',
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
                'label'       => 'XXX-XXX-XXXX-ESC-XXX-TPL',
                'message'     => $message,
                'expected'    => 'sample &lt;phalcon&gt; message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => true,
                'implicit'    => false,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-XXXX-ESC-XXX-XXX',
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
                'label'       => 'XXX-XXX-XXXX-XXX-IMP-TPL',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => true,
                'template'    => $template,
            ],
            [
                'label'       => 'XXX-XXX-XXXX-XXX-IMP-XXX',
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
                'label'       => 'XXX-XXX-XXXX-XXX-XXX-TPL',
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
                'label'       => 'XXX-XXX-XXXX-XXX-XXX-XXX',
                'message'     => $message,
                'expected'    => 'sample <phalcon> message',
                'classes'     => [],
                'iconClasses' => [],
                'autoHtml'    => false,
                'autoescape'  => false,
                'implicit'    => false,
                'template'    => '',
            ],
        ];
    }
}
