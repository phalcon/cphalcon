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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

class FunctionCallTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                '{{ content() }}',
                '<?= $this->getContent() ?>',
            ],
            [
                '{{ content() }}',
                '<?= $this->getContent() ?>',
            ],
            [
                '{{ partial("abc.volt") }}',
                '<?= $this->partial(\'abc.volt\') ?>',
            ],
            // Phalcon\Tag
            [
                '{{ link_to(\'abc\') }}',
                '<?= \Phalcon\Tag::linkTo([\'abc\']) ?>',
            ],
            [
                '{{ image(\'abc\') }}',
                '<?= \Phalcon\Tag::image([\'abc\']) ?>',
            ],
            [
                '{{ form_legacy(\'abc\') }}',
                '<?= \Phalcon\Tag::formLegacy([\'abc\']) ?>',
            ],
            [
                '{{ submit_button(\'abc\') }}',
                '<?= \Phalcon\Tag::submitButton([\'abc\']) ?>',
            ],
            [
                '{{ radio_field(\'abc\') }}',
                '<?= \Phalcon\Tag::radioField([\'abc\']) ?>',
            ],
            [
                '{{ check_field(\'abc\') }}',
                '<?= \Phalcon\Tag::checkField([\'abc\']) ?>',
            ],
            [
                '{{ file_field(\'abc\') }}',
                '<?= \Phalcon\Tag::fileField([\'abc\']) ?>',
            ],
            [
                '{{ hidden_field(\'abc\') }}',
                '<?= \Phalcon\Tag::hiddenField([\'abc\']) ?>',
            ],
            [
                '{{ password_field(\'abc\') }}',
                '<?= \Phalcon\Tag::passwordField([\'abc\']) ?>',
            ],
            [
                '{{ text_area(\'abc\') }}',
                '<?= \Phalcon\Tag::textArea([\'abc\']) ?>',
            ],
            [
                '{{ text_field(\'abc\') }}',
                '<?= \Phalcon\Tag::textField([\'abc\']) ?>',
            ],
            [
                '{{ email_field(\'abc\') }}',
                '<?= \Phalcon\Tag::emailField([\'abc\']) ?>',
            ],
            [
                '{{ date_field(\'abc\') }}',
                '<?= \Phalcon\Tag::dateField([\'abc\']) ?>',
            ],
            [
                '{{ tel_field(\'abc\') }}',
                '<?= \Phalcon\Tag::telField([\'abc\']) ?>',
            ],
            [
                '{{ numeric_field(\'abc\') }}',
                '<?= \Phalcon\Tag::numericField([\'abc\']) ?>',
            ],
            [
                '{{ image_input(\'abc\') }}',
                '<?= \Phalcon\Tag::imageInput([\'abc\']) ?>',
            ],
            [
                '{{ url(\'abc\') }}',
                '<?= $this->url->get(\'abc\') ?>',
            ],
            [
                '{{ static_url(\'abc\') }}',
                '<?= $this->url->getStatic(\'abc\') ?>',
            ],
            [
                '{{ date(\'abc\') }}',
                '<?= date(\'abc\') ?>',
            ],
            [
                '{{ time() }}',
                '<?= time() ?>',
            ],
            [
                '{{ dump(\'abc\') }}',
                '<?= var_dump(\'abc\') ?>',
            ],
            [
                '{{ version() }}',
                '<?= (new Phalcon\Support\Version)->get() ?>',
            ],
            [
                '{{ version_id() }}',
                '<?= (new Phalcon\Support\Version)->getId() ?>',
            ],
            [
                '{{ constant(\'abc\') }}',
                '<?= constant(\'abc\') ?>',
            ],
            [
                '{{ preload(\'abc.css\') }}',
                '<?= $this->preload(\'abc.css\') ?>',
            ],
            [
                '{{ preload(\'abc.jpg\', [\'as\' : \'image\']) }}',
                '<?= $this->preload(\'abc.jpg\', [\'as\' => \'image\']) ?>',
            ],
            [
                '{{ somefunction(\'abc\') }}',
                '<?= $this->callMacro(\'somefunction\', [\'abc\']) ?>',
            ],
            [
                '{{ "abc" | length }}',
                '<?= $this->length(\'abc\') ?>',
            ],
            [
                '{{ "abc" | e }}',
                '<?= $this->escaper->html(\'abc\') ?>',
            ],
            [
                '{{ "abc" | escape }}',
                '<?= $this->escaper->html(\'abc\') ?>',
            ],
            [
                '{{ "abc" | escape_css }}',
                '<?= $this->escaper->css(\'abc\') ?>',
            ],
            [
                '{{ "abc" | escape_js }}',
                '<?= $this->escaper->js(\'abc\') ?>',
            ],
            [
                '{{ "abc" | escape_attr }}',
                '<?= $this->escaper->attributes(\'abc\') ?>',
            ],
            [
                '{{ "abc" | trim }}',
                '<?= trim(\'abc\') ?>',
            ],
            [
                '{{ "abc" | left_trim }}',
                '<?= ltrim(\'abc\') ?>',
            ],
            [
                '{{ "abc" | right_trim }}',
                '<?= rtrim(\'abc\') ?>',
            ],
            [
                '{{ "abc" | striptags }}',
                '<?= strip_tags(\'abc\') ?>',
            ],
            [
                '{{ "abc" | url_encode }}',
                '<?= urlencode(\'abc\') ?>',
            ],
            [
                '{{ "abc" | striptags }}',
                '<?= strip_tags(\'abc\') ?>',
            ],
            [
                '{{ "abc" | slashes }}',
                '<?= addslashes(\'abc\') ?>',
            ],
            [
                '{{ "abc" | stripslashes }}',
                '<?= stripslashes(\'abc\') ?>',
            ],
            [
                '{{ "abc" | nl2br }}',
                '<?= nl2br(\'abc\') ?>',
            ],
            [
                '{{ "abc" | keys }}',
                '<?= array_keys(\'abc\') ?>',
            ],
            [
                '{{ ["abc", "def"] | join(",") }}',
                '<?= join(\',\', [\'abc\', \'def\']) ?>',
            ],
            [
                '{{ "abc" | lower }}',
                '<?= $this->helper->lower(\'abc\') ?>',
            ],
            [
                '{{ "abc" | lowercase }}',
                '<?= $this->helper->lower(\'abc\') ?>',
            ],
            [
                '{{ "abc" | upper }}',
                '<?= $this->helper->upper(\'abc\') ?>',
            ],
            [
                '{{ "abc" | uppercase }}',
                '<?= $this->helper->upper(\'abc\') ?>',
            ],
            [
                '{{ "abc" | capitalize }}',
                '<?= ucwords(\'abc\') ?>',
            ],
            [
                '{{ "abc" | sort }}',
                '<?= $this->sort(\'abc\') ?>',
            ],
            [
                '{{ "abc" | json_encode }}',
                '<?= json_encode(\'abc\') ?>',
            ],
            [
                '{{ "abc" | json_decode }}',
                '<?= json_decode(\'abc\') ?>',
            ],
            [
                '{{ "abc" | format }}',
                '<?= sprintf(\'abc\') ?>',
            ],
            [
                '{{ "abc" | abs }}',
                '<?= abs(\'abc\') ?>',
            ],
            [
                '{{ "abc" | slice }}',
                '<?= $this->slice(\'abc\') ?>',
            ],
            [
                '{{ "abc" | default("def") }}',
                '<?= (empty(\'abc\') ? (\'def\') : (\'abc\')) ?>',
            ],
            [
                '{{ "abc" | convert_encoding }}',
                '<?= $this->convertEncoding(\'abc\') ?>',
            ],
            // Tag Factory
            [
                '{{ a("https://phalcon.io/", "home") }}',
                '<?= $this->tag->a("https://phalcon.io/", "home") ?>',
            ],
            [
                '{{ base("https://phalcon.io/") }}',
                '<?= $this->tag->base("https://phalcon.io/") ?>',
            ],
            [
                '{{ body() }}',
                '<?= $this->tag->body() ?>',
            ],
            [
                '{{ button("close", ["class" : "label label-info"]) }}',
                '<?= $this->tag->button("close", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ close("form") }}',
                '<?= $this->tag->close("form") ?>',
            ],
            [
                '{{ doctype(5, "\n\n") }}',
                '<?= $this->tag->doctype(5, "\n\n") ?>',
            ],
            [
                '{{ element("button", "close", ["class" : "label label-info"]) }}',
                '<?= $this->tag->element("button", "close", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ form(["class" : "label label-info"]) }}',
                '<?= $this->tag->form([\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ img("/img/abc.jpg") }}',
                '<?= $this->tag->img("/img/abc.jpg") ?>',
            ],
            [
                '{{ inputCheckbox("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputCheckbox("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputColor("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputColor("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputDate("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputDate("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputDateTime("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputDateTime("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputDateTimeLocal("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputDateTimeLocal("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputEmail("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputEmail("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputFile("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputFile("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputHidden("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputHidden("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputImage("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputImage("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputInput("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputInput("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputMonth("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputMonth("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputNumeric("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputNumeric("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputPassword("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputPassword("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputRadio("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputRadio("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputRange("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputRange("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputSearch("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputSearch("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputSelect("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputSelect("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputSubmit("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputSubmit("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputTel("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputTel("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputText("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputText("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputTextarea("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputTextarea("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputTime("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputTime("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputUrl("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputUrl("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ inputWeek("test", "1", ["class" : "label label-info"]) }}',
                '<?= $this->tag->inputWeek("test", "1", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ label("test", ["class" : "label label-info"]) }}',
                '<?= $this->tag->label("test", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ link("\t", "\n\n") }}',
                '<?= $this->tag->link("\t", "\n\n") ?>',
            ],
            [
                '{{ meta("\t", "\n\n") }}',
                '<?= $this->tag->meta("\t", "\n\n") ?>',
            ],
            [
                '{{ ol("test", ["class" : "label label-info"]) }}',
                '<?= $this->tag->ol("test", [\'class\' => "label label-info"]) ?>',
            ],
            [
                '{{ script("\t", "\n\n") }}',
                '<?= $this->tag->script("\t", "\n\n") ?>',
            ],
            [
                '{{ style("\t", "\n\n") }}',
                '<?= $this->tag->style("\t", "\n\n") ?>',
            ],
            [
                '{{ style("\t", "\n\n") }}',
                '<?= $this->tag->style("\t", "\n\n") ?>',
            ],
            [
                '{{ title("\t", "\n\n") }}',
                '<?= $this->tag->title("\t", "\n\n") ?>',
            ],
            [
                '{{ ul("test", ["class" : "label label-info"]) }}',
                '<?= $this->tag->ul("test", [\'class\' => "label label-info"]) ?>',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-11
     */
    public function testMvcViewEngineVoltCompilerFunctionCall(
        string $source,
        string $expected
    ): void {
        $this->setNewFactoryDefault();

        $volt = new Compiler();
        $volt->setDI($this->container);

        $actual = $volt->compileString($source);

        $this->assertSame($expected, $actual);
    }
}
