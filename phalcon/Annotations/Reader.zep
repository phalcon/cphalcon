
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use ReflectionClass;

/**
 * Parses docblocks returning an array with the found annotations
 */
class Reader implements ReaderInterface
{
    /**
     * Reads annotations from the class docblocks, its methods and/or properties
     */
    public function parse(string className) -> array
    {
        var reflection, comment, line, arrayKeys, classAnnotations,
            properties,  property, annotationsProperties, propertyAnnotations,
            methods, method, annotationsMethods, methodAnnotations,
            constants, constant, anotationsConstants, constantAnnotations, constantReflection;
        array annotations;

        let annotations = [];

        /**
         * A ReflectionClass is used to obtain the class docblock
         */
        let reflection = new ReflectionClass(className);

        let comment = reflection->getDocComment();
        if typeof comment == "string" {
            /**
             * Read annotations from class
             */
            let classAnnotations = phannot_parse_annotations(
                comment,
                reflection->getFileName(),
                reflection->getStartLine()
            );

            /**
             * Append the class annotations to the annotations var
             */
            if typeof classAnnotations == "array" {
                let annotations["class"] = classAnnotations;
            }
        }

        /**
         * Get class constants
         */
        let constants = reflection->getConstants();

        if count(constants) {
            /**
             * Line declaration for constants isn't available
             */
            let line = 1;
            let arrayKeys = array_keys(constants);
            let anotationsConstants = [];

            for constant in arrayKeys {
                /**
                 * Read comment from constant docblock
                 */
                let constantReflection = reflection->getReflectionConstant(constant);
                let comment = constantReflection->getDocComment();

                if typeof comment == "string" {
                    /**
                     * Parse constant docblock comment
                     */
                    let constantAnnotations = phannot_parse_annotations(
                        comment,
                        reflection->getFileName(),
                        line
                    );

                    if typeof constantAnnotations == "array" {
                        let anotationsConstants[constant] = constantAnnotations;
                    }
                }
            }

            if count(anotationsConstants) {
                let annotations["constants"] = anotationsConstants;
            }
        }

        /**
         * Get the class properties
         */
        let properties = reflection->getProperties();

        if count(properties) {
            /**
             * Line declaration for properties isn't available
             */
            let line = 1;
            let annotationsProperties = [];

            for property in properties {
                /**
                 * Read comment from property
                 */
                let comment = property->getDocComment();

                if typeof comment == "string" {
                    /**
                     * Parse property docblock comment
                     */
                    let propertyAnnotations = phannot_parse_annotations(
                        comment,
                        reflection->getFileName(),
                        line
                    );

                    if typeof propertyAnnotations == "array" {
                        let annotationsProperties[property->name] = propertyAnnotations;
                    }
                }
            }

            if count(annotationsProperties) {
                let annotations["properties"] = annotationsProperties;
            }
        }

        /**
         * Get the class methods
         */
        let methods = reflection->getMethods();

        if count(methods) {
            let annotationsMethods = [];

            for method in methods {
                /**
                 * Read comment from method
                 */
                let comment = method->getDocComment();

                if typeof comment == "string" {
                    /**
                     * Parse method docblock comment
                     */
                    let methodAnnotations = phannot_parse_annotations(
                        comment,
                        method->getFileName(),
                        method->getStartLine()
                    );

                    if typeof methodAnnotations == "array" {
                        let annotationsMethods[method->name] = methodAnnotations;
                    }
                }
            }

            if count(annotationsMethods) {
                let annotations["methods"] = annotationsMethods;
            }
        }

        return annotations;
    }

    /**
     * Parses a raw doc block returning the annotations found
     */
    public static function parseDocBlock(string docBlock, file = null, line = null) -> array
    {
        if typeof file != "string" {
            let file = "eval code";
        }

        return phannot_parse_annotations(docBlock, file, line);
    }
}
