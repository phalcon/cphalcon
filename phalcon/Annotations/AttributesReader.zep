
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Contracts\Annotations\AnnotationsTypes;
use ReflectionClass;

/**
 * Parses PHP attributes returning an array with the found annotations
 *
 * The array has the same shape as the one of Phalcon\Annotations\Reader, so
 * the adapters, Reflection, Collection and Annotation do not know which
 * reader made it.
 *
 * PHP resolves the value of an attribute argument, so there is no parse tree
 * to walk. Each value goes in a node of the type Annotation::T_RESOLVED,
 * which Annotation::getExpression() gives back without a change.
 *
 * @phpstan-import-type annotations_arguments from AnnotationsTypes
 * @phpstan-import-type annotations_node_list from AnnotationsTypes
 * @phpstan-import-type annotations_reflection_data from AnnotationsTypes
 */
class AttributesReader implements ReaderInterface
{
    /**
     * An attribute of this namespace gets the short name, so that `#[Column]`
     * and `@Column` give the same name. Every other attribute keeps the full
     * class name, so that an attribute of another library cannot take the
     * place of a Phalcon one.
     *
     * @var string
     */
    const PHALCON_NAMESPACE = "Phalcon\\Annotations\\";

    /**
     * Reads attributes from the class, its constants, properties and methods
     *
     * @phpstan-param class-string $className
     *
     * @phpstan-return annotations_reflection_data
     */
    public function parse(string className) -> array
    {
        var reflection, file, line, classAttributes, constant, constants,
            constantAttributes, annotationsConstants, property, properties,
            propertyAttributes, annotationsProperties, method, methods,
            methodAttributes, annotationsMethods, methodFile;
        array annotations;

        let annotations = [],
            reflection  = new ReflectionClass(className),
            file        = reflection->getFileName();

        /**
         * An internal class has no file
         */
        if typeof file !== "string" {
            let file = "eval code";
        }

        /**
         * Read the attributes of the class
         */
        let line            = (int) reflection->getStartLine(),
            classAttributes = this->buildNodes(
                reflection->getAttributes(),
                file,
                line
            );

        if !empty classAttributes {
            let annotations["class"] = classAttributes;
        }

        /**
         * Read the attributes of the constants. A constant has no line, the
         * same as in the docblock reader.
         */
        let constants            = reflection->getReflectionConstants(),
            annotationsConstants = [];

        for constant in constants {
            let constantAttributes = this->buildNodes(
                constant->getAttributes(),
                file,
                1
            );

            if !empty constantAttributes {
                let annotationsConstants[constant->getName()] = constantAttributes;
            }
        }

        if !empty annotationsConstants {
            let annotations["constants"] = annotationsConstants;
        }

        /**
         * Read the attributes of the properties. A property has no line.
         */
        let properties            = reflection->getProperties(),
            annotationsProperties = [];

        for property in properties {
            let propertyAttributes = this->buildNodes(
                property->getAttributes(),
                file,
                1
            );

            if !empty propertyAttributes {
                let annotationsProperties[property->name] = propertyAttributes;
            }
        }

        if !empty annotationsProperties {
            let annotations["properties"] = annotationsProperties;
        }

        /**
         * Read the attributes of the methods
         */
        let methods            = reflection->getMethods(),
            annotationsMethods = [];

        for method in methods {
            let methodFile = method->getFileName();

            if typeof methodFile !== "string" {
                let methodFile = "eval code";
            }

            let methodAttributes = this->buildNodes(
                method->getAttributes(),
                methodFile,
                (int) method->getStartLine()
            );

            if !empty methodAttributes {
                let annotationsMethods[method->name] = methodAttributes;
            }
        }

        if !empty annotationsMethods {
            let annotations["methods"] = annotationsMethods;
        }

        return annotations;
    }

    /**
     * Makes the argument list of one attribute. PHP resolved the values
     * already, so each one goes in a node that Annotation::getExpression()
     * gives back without a change. An integer key is a positional argument
     * and a string key is a named one.
     *
     * @phpstan-param array<array-key, mixed> $attributeArguments
     *
     * @phpstan-return annotations_arguments
     */
    protected function buildArguments(array attributeArguments) -> array
    {
        var key, value, argument;
        array arguments;

        let arguments = [];

        for key, value in attributeArguments {
            let argument = [
                "expr": [
                    "type":  Annotation::T_RESOLVED,
                    "value": value
                ]
            ];

            if typeof key === "string" {
                let argument["name"] = key;
            }

            let arguments[] = argument;
        }

        return arguments;
    }

    /**
     * Makes the node list of one target from its attributes
     *
     * @phpstan-param array<array-key, \ReflectionAttribute<object>> $attributes
     *
     * @phpstan-return annotations_node_list
     */
    protected function buildNodes(array attributes, string file, int line) -> array
    {
        var attribute, name, attributeArguments, node;
        array nodes;

        let nodes = [];

        for attribute in attributes {
            let name = attribute->getName();

            if starts_with(name, self::PHALCON_NAMESPACE) {
                let name = get_class_ns(name);
            }

            /**
             * The node carries the same keys as the one the parser builds,
             * so that Reflection::getReflectionData() gives one shape
             * whichever reader filled it.
             */
            let node = [
                "type": PHANNOT_T_ANNOTATION,
                "name": name,
                "file": file,
                "line": line
            ];

            let attributeArguments = attribute->getArguments();

            if !empty attributeArguments {
                let node["arguments"] = this->buildArguments(attributeArguments);
            }

            let nodes[] = node;
        }

        return nodes;
    }
}
